#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

bool isShutDown = false;

void renderingThread(sf::RenderWindow* window)
{
    try
    {

        // the rendering loop
        while (!isShutDown)
        {
            if (window)
            {
                // clear
                window->clear(sf::Color::White);


                // Draw
                sf::CircleShape shape(50);
                // set the shape color to green
                shape.setFillColor(sf::Color(100, 250, 50));
                window->draw(shape);
                // end the current frame
                window->display();
            }
            else
            {
                std::cout << " No Window... " << std::endl;
            }
        }
    }
    catch (const std::exception& err)
    {
        std::cout << " Exception: " << err.what() << std::endl;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(100.0, 100.0));
    //window.setActive(false);

    //sf::Thread thread(&renderingThread, &window);
    //thread.launch();

    float boxX = 0.0;
    float boxY = 0.0;

    std::string imageFile = "/Users/ankithbti/Development/gameBasics/bin/box.png";
    sf::Image image;
    if (!image.loadFromFile(imageFile))
    {
        std::cout << " Can not load image " << std::endl;
    }
    else
    {
        std::cout << " Image loaded successfully. " << std::endl;
    }

    std::string groundImageFile = "/Users/ankithbti/Development/gameBasics/bin/dirt.jpg";
    sf::Image groundImage;
    if (!groundImage.loadFromFile(groundImageFile))
    {
        std::cout << " Can not load image " << std::endl;
    }
    else
    {
        std::cout << " Image loaded successfully. " << std::endl;
    }

    image.createMaskFromColor(sf::Color::Yellow, 255);
    groundImage.createMaskFromColor(sf::Color::Yellow, 255);

    sf::Sprite spriteImage;
    sf::Texture texture;
    texture.loadFromImage(image, sf::IntRect(10, 10, 32, 32));
    spriteImage.setTexture(texture);
    //spriteImage.setPosition(600, 100);
    //spriteImage.setScale(0.5, 0.5);

    sf::Sprite spriteGroundImage;
    sf::Texture groundTexture;
    //sf::IntRect recGound(10,10,200,200);
    groundTexture.loadFromImage(groundImage); /*, recGound);*/
    spriteGroundImage.setTexture(groundTexture, true);
    //spriteGroundImage.setPosition(0, 580);
    //spriteGroundImage.setTextureRect(sf::IntRect(0, 0, 800, 50));




    // Set up the World
    b2Vec2 gravity(0.0f, 9.81f);
    bool doSleep = true;
    int iterations = 10;
    float scale = 30; // To convert Meters to Pixels ( 1 Mtr = 30 Pxl )
    float timestamp = 1 / 60;

    // Create the Size of the World
//    b2AABB worldAABB;
//    worldAABB.lowerBound = b2Vec2(-1000 / scale, -1000 / scale); // -1000 - Unit in Meters
//    worldAABB.upperBound = b2Vec2(1000 / scale, 1000 / scale);

    b2World * world = new b2World(gravity);
    //world->DrawDebugData();
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    world->SetAutoClearForces (false);
    // Create Ground
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(400 / scale, 580 / scale);
    BodyDef.type = b2_staticBody;
    b2Body* Body = world->CreateBody(&BodyDef);
    b2PolygonShape Shape;
    Shape.SetAsBox((800.f / 2) / scale, (20.f / 2) / scale); // Creates a box shape. Divide your desired width and height by 2.
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f; // Sets the density of the body
    FixtureDef.shape = &Shape; // Sets the shape
    Body->CreateFixture(&FixtureDef); // Apply the fixture definition



    sf::Event event;
    // run the program as long as the window is open
    while (window.isOpen())
    {

        while (window.pollEvent(event) && !isShutDown)
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                std::cout << " Closing WIndow... " << std::endl;
                //thread.terminate();
                //thread.wait();
                isShutDown = true;
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                std::cout << " Escape Closing WIndow... " << std::endl;
                //thread.terminate();
                //thread.wait();
                isShutDown = true;
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << " Mouse Left Button Pressed at " <<
                        sf::Mouse::getPosition(window).x << "," <<
                        sf::Mouse::getPosition(window).y << std::endl;
                float mouseX = sf::Mouse::getPosition(window).x;
                float mouseY = sf::Mouse::getPosition(window).y;
                ++boxX;
                // Add Dynamic Box
                b2BodyDef BodyDef;
                BodyDef.position = b2Vec2(mouseX / scale, mouseY / scale);
                BodyDef.type = b2_dynamicBody;
                b2Body* Body = world->CreateBody(&BodyDef);

                b2PolygonShape Shape;
                Shape.SetAsBox((32.f / 2) / scale, (32.f / 2) / scale);
                b2FixtureDef FixtureDef;
                FixtureDef.density = 1.f;
                FixtureDef.friction = 0.7f;
                FixtureDef.shape = &Shape;
                Body->CreateFixture(&FixtureDef);
            }
        }

            
            
            // clear
            window.clear(sf::Color::White);
            
            

            // Draw World
            for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
            {
                if (BodyIterator->GetType() == b2_dynamicBody)
                {
                    spriteImage.setOrigin(16.f, 16.f);
                    spriteImage.setPosition(scale * BodyIterator->GetPosition().x, scale * BodyIterator->GetPosition().y);
                    spriteImage.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
                    window.draw(spriteImage);
                }
                else
                {
                    // Static Ground like Body
                    //                    sf::Sprite GroundSprite;
                    //                    GroundSprite.setTexture(groundTexture);
                    //                    GroundSprite.setOrigin(400.f, 8.f);
                    spriteGroundImage.setOrigin(400.f, 10.f);
                    spriteGroundImage.setPosition(BodyIterator->GetPosition().x * scale, BodyIterator->GetPosition().y * scale);
                    spriteGroundImage.setTextureRect(sf::IntRect(0, 0, 800, 20));
                    //GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
                    //GroundSprite.SetRotation(180 / b2_pi * BodyIterator->GetAngle());
                    //windowDraw(GroundSprite);
                    window.draw(spriteGroundImage);
                }
            }

            world->Step(1/60.0f, 8, 3);
            
            // Draw
            sf::CircleShape shape(50);
            // set the shape color to green
            shape.setFillColor(sf::Color(100, 250, 50));
            shape.setPosition(300, 100);

            //window.draw(shape);

            sf::RectangleShape box(sf::Vector2f(20.0, 10.0));
            box.setPosition(boxX, boxY);
            box.setFillColor(sf::Color::Cyan);
            //window.draw(box);

            // Draw Sprite
            //window.draw(spriteImage);

            //            window.draw(spriteGroundImage);
            
            // end the current frame
            window.display();
        

    } // outer while

    return 0;
}

//
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
//
///** We need this to easily convert between pixel and real-world coordinates*/
//static const float SCALE = 30.f;
//
///** Create the base for the boxes to land */
//void CreateGround(b2World& World, float X, float Y);
//
///** Create the boxes */
//void CreateBox(b2World& World, int MouseX, int MouseY);
//
//int main()
//{
//    /** Prepare the window */
//    sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Test");
//    Window.setFramerateLimit(60);
//
//    /** Prepare the world */
//    b2Vec2 Gravity(0.f, 9.8f);
//    b2World World(Gravity);
//    CreateGround(World, 400.f, 500.f);
//
//    /** Prepare textures */
//    sf::Texture GroundTexture;
//    sf::Texture BoxTexture;
//    GroundTexture.loadFromFile("/Users/ankithbti/Development/gameBasics/bin/ground.png");
//    BoxTexture.loadFromFile("/Users/ankithbti/Development/gameBasics/bin/box.png");
//
//    while (Window.isOpen())
//    {
//        /** When the user left-mouse-click, add a box into the world */
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            int MouseX = sf::Mouse::getPosition(Window).x;
//            int MouseY = sf::Mouse::getPosition(Window).y;
//            CreateBox(World, MouseX, MouseY);
//        }
//
//        World.Step(1 / 60.f, 8, 3);
//
//        Window.clear(sf::Color::White);
//        int BodyCount = 0;
//        
//        for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
//        {
//            if (BodyIterator->GetType() == b2_dynamicBody)
//            {
//                sf::Sprite Sprite;
//                Sprite.setTexture(BoxTexture);
//                Sprite.setOrigin(16.f, 16.f);
//                Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
//                Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
//                Window.draw(Sprite);
//                ++BodyCount;
//            }
//            else
//            {
//                sf::Sprite GroundSprite;
//                GroundSprite.setTexture(GroundTexture);
//                GroundSprite.setOrigin(400.f, 8.f);
//                GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
//                GroundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
//                Window.draw(GroundSprite);
//            }
//        }
//        Window.display();
//    }
//
//    return 0;
//}
//
//void CreateBox(b2World& World, int MouseX, int MouseY)
//{
//    b2BodyDef BodyDef;
//    BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
//    BodyDef.type = b2_dynamicBody;
//    b2Body* Body = World.CreateBody(&BodyDef);
//
//    b2PolygonShape Shape;
//    Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
//    b2FixtureDef FixtureDef;
//    FixtureDef.density = 1.f;
//    FixtureDef.friction = 0.7f;
//    FixtureDef.shape = &Shape;
//    Body->CreateFixture(&FixtureDef);
//}
//
//void CreateGround(b2World& World, float X, float Y)
//{
//    b2BodyDef BodyDef;
//    BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
//    BodyDef.type = b2_staticBody;
//    b2Body* Body = World.CreateBody(&BodyDef);
//
//    b2PolygonShape Shape;
//    Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
//    b2FixtureDef FixtureDef;
//    FixtureDef.density = 0.f;
//    FixtureDef.shape = &Shape;
//    Body->CreateFixture(&FixtureDef);
//}