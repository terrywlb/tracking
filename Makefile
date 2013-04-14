PROGRAM=traking
ROOT_DIR=./
BIN_DIR=bin/
INCLUDE_DIR=/usr/local/include/opencv/
LINK_FLAGS=-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
CC=g++
FILES=*.c*
COMPILE_FLAGS=-I$(INCLUDE_DIR) -g
DEBUGER=gdb
DEBUG_FLAGS=-tui
make:
	rm -rf $(ROOT_DIR)$(BIN_DIR)
	$(CC) -o $(PROGRAM) $(FILES) $(COMPILE_FLAGS) $(LINK_FLAGS)
	mkdir $(ROOT_DIR)$(BIN_DIR)
	mv $(PROGRAM) $(ROOT_DIR)$(BIN_DIR)

run:
	$(ROOT_DIR)$(BIN_DIR)$(PROGRAM)

debug:
	$(DEBUGER) $(DEBUG_FLAGS) $(ROOT_DIR)$(BIN_DIR)$(PROGRAM)