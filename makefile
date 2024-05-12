BUILD_DIR := build
ZIPNAME := xlindo04-xmrave02.zip
TARGET := icp24 
FILES := header/* src/* Makefile README.txt Doxyfile CMakeLists.txt Conceptual_design.pdf
DOC := doc

.PHONY: all clean run doc
all:$(TARGET)

$(TARGET):
	mkdir -p build
	cd build &&  cmake .. && make
clean:
	rm -rf $(BUILD_DIR) $(DOC) $(ZIPFILE)

run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

doc: doxygen

doxygen:
	doxygen Doxyfile

pack:
	zip $(ZIPNAME) $(FILES)
