###############
## Makefile
###############

BIN=../bin/gameEngineCpp
BOOST_INSTALL_ROOT=/Users/ankithbti/Development/Cpp/boost
HTTP_SERVER_BASE=/Users/ankithbti/Development/Cpp/httpServer
GLFW_BASE=/Users/ankithbti/Development/glfw
GLEW_BASE=/Users/ankithbti/Development/glew
BOX2D_BASE=/Users/ankithbti/Development/box2d_install
SDL_BASE=/Users/ankithbti/Development/sdl_install
SFML_BASE=/Users/ankithbti/Development/sfml_install

ARCH = $(shell uname -m)	# ARCH becomes the output from the uname -m command.
CXX=/usr/bin/g++
CXXFLAGS=-g -O2 -Wall $(INCS)

SRCS_OLD = Game.cpp SplashScreen.cpp MainMenu.cpp PlayerPaddle.cpp VisibleGameObject.cpp \
	GameObjectManager.cpp \
	Ball.cpp \
	Ground.cpp \
	Box.cpp \
	ScoreText.cpp \
	MyDebugDraw.cpp \
	MyContactListener.cpp \
	Enemy.cpp \
	SFMLAudioProvider.cpp \
	AudioServiceLocator.cpp \
	
SRCS = Log.cpp \
	GameScreen.cpp \
	GameEntity.cpp \
	GameEntityManager.cpp \
	Tank.cpp \
	GameMapLoader.cpp \
	GameEntityFactory.cpp \
	Wall.cpp \
	Eagle.cpp \
	
	
MAIN_SRC = Main.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MAIN_OBJ = $(patsubst %.cpp, %.o, $(MAIN_SRC))

INCS = -I../include \
       -I$(BOOST_INSTALL_ROOT)/include \
       -I${BOX2D_BASE}/include \
       -I${SFML_BASE}/include \
## -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
LIBS = \
	-L${BOOST_INSTALL_ROOT}/lib -lboost_system \
        -L${BOOST_INSTALL_ROOT}/lib -lboost_thread \
	-L${BOOST_INSTALL_ROOT}/lib -lboost_date_time \
	${BOX2D_BASE}/lib/libBox2D.a \
        -L${SFML_BASE}/lib -lsfml-system -lsfml-window -lsfml-audio -lsfml-graphics -lsfml-network \
	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
	-lpthread
	
$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CXX) -o $(BIN) $(OBJS) $(MAIN_OBJ) $(LIBS)

all: $(BIN)

run:
	@echo "----------------------------"
	@echo "Running the programme. "
	@echo "----------------------------"
	$(BIN)
	@echo "----------------------------"

clean:
	rm -rf $(BIN) *.o
