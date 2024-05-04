DOC := doc
ZIPFILE := xmrave02-xlindo04.zip
ZIPFILES := header/* src/* Makefile README.md Doxyfile CMakeLists.txt
BUILD_DIR := build
TARGET := icp24 
# Targets
.PHONY: all clean run doc
all:$(TARGET)

$(TARGET):
	mkdir -p build
	cd build && cmake .. && make
clean:
	rm -rf $(BUILD_DIR) $(DOC) $(ZIPFILE)

run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

doxygen:
	doxygen Doxyfile

pack:
	zip $(ZIPFILE) $(ZIPFILES)
