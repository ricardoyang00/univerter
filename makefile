CXX = g++
CXXFLAGS = -std=c++11
SRC = converter.cpp
TARGET = converter

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET)
