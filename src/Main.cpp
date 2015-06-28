#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

bool isShutDown = false;
// Set up the World
b2Vec2 gravity(0.0f, 9.81f);
bool doSleep = true;
int iterations = 10;
float scale = 30; // To convert Meters to Pixels ( 1 Mtr = 30 Pxl )
float timestamp = 1 / 60;
b2World * world;
sf::Sprite spriteImage;
sf::Sprite spriteGroundImage;
boost::mutex m;

void createGround()
{
    if (!world)
    {
        return;
    }
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

}

void renderingThread(sf::RenderWindow* window)
{
    try
    {
        //window->setActive(true);
        // the rendering loop
        while (!isShutDown)
        {
            if (window)
            {
                //boost::lock_guard<boost::mutex> lock(m);
                // clear
                window->clear(sf::Color::White);


                sf::CircleShape shape(50);
                //        // set the shape color to green
                shape.setFillColor(sf::Color(100, 250, 50));
                shape.setPosition(300, 100);
                //
                window->draw(shape);


                // Draw World
                for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
                {
                    if (BodyIterator->GetType() == b2_dynamicBody)
                    {
                        spriteImage.setOrigin(16.f, 16.f);
                        spriteImage.setPosition(scale * BodyIterator->GetPosition().x, scale * BodyIterator->GetPosition().y);
                        spriteImage.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
                        window->draw(spriteImage);
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
                        window->draw(spriteGroundImage);
                    }
                } // end of world body drawing

                {
                    boost::lock_guard<boost::mutex> lock(m);
                    world->Step(1 / 60.0f, 8, 3);
                }
                // end the cu   rrent frame
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
    std::cout << " Ending Render Thread... " << std::endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(100.0, 100.0));

    window.setActive(false);

    // World
    world = new b2World(gravity);
    //world->DrawDebugData();
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    world->SetAutoClearForces(false);

    createGround();


    //sf::Thread thread(&renderingThread, &window);
    //thread.launch();

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


    sf::Texture texture;
    texture.loadFromImage(image, sf::IntRect(10, 10, 32, 32));
    spriteImage.setTexture(texture);
    //spriteImage.setPosition(600, 100);
    //spriteImage.setScale(0.5, 0.5);


    sf::Texture groundTexture;
    //sf::IntRect recGound(10,10,200,200);
    groundTexture.loadFromImage(groundImage); /*, recGound);*/
    spriteGroundImage.setTexture(groundTexture, true);
    //spriteGroundImage.setPosition(0, 580);
    //spriteGroundImage.setTextureRect(sf::IntRect(0, 0, 800, 50));

    boost::thread t(renderingThread, &window);

    // run the program as long as the window is open
    while (!isShutDown)
    {

        //boost::lock_guard<boost::mutex> lock(m);

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                std::cout << " Closing WIndow... " << std::endl;
                //thread.terminate();
                //thread.wait();
                isShutDown = true;
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

                // Add Dynamic Box
                b2BodyDef BodyDef;
                BodyDef.position = b2Vec2(mouseX / scale, mouseY / scale);
                BodyDef.type = b2_dynamicBody;
                b2Body* Body;
                {
                    boost::lock_guard<boost::mutex> lock(m);
                    Body = world->CreateBody(&BodyDef);
                }
                b2PolygonShape Shape;
                Shape.SetAsBox((32.f / 2) / scale, (32.f / 2) / scale);
                b2FixtureDef FixtureDef;
                FixtureDef.density = 1.f;
                FixtureDef.friction = 0.7f;
                FixtureDef.shape = &Shape;
                Body->CreateFixture(&FixtureDef);
            }
            //
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {

            }
        }// end of event

    }

    if (t.joinable())
        t.join();
    window.close();
    std::cout << " Ending Main Thread...." << std::endl;

    return 0;
}