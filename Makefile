wxmapedit:
	c++ -Wall -o build/wxmapedit src/main.cpp `wx-config --cxxflags` `wx-config --libs`