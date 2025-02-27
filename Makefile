CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = program
SOURCES = main.cpp
HEADERS = Node.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) 
