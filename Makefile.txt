wxmapedit:
	c++ -Wall -o build/wxmapedit src/App.cpp src/Main.cpp src/MapView.cpp src/map.c -Iinclude `wx-config --cxxflags` `wx-config --libs`