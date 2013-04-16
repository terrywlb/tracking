PROJECT_NAME=traking
ROOT_DIR=./
OBJ_DIR=obj/
SRC_DIR=src/
HDR_DIR=hdr/
BIN_DIR=bin/

SRC_FOLDERS=$(shell cd $(SRC_DIR); find -type d -name "??*")
LINK_FLAGS=-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
CC=g++
DEBUGER=gdb
DEBUG_FLAGS=-tui

all:
	make build_obj
	make link_obj

build_obj:
	make collect_heades
	rm -rf ./$(OBJ_DIR)/
	mkdir -p $(OBJ_DIR)
	cd $(SRC_DIR);for f in $(SRC_FOLDERS); do cd $$f/; make; cd ..; done
	cp -rf $$(find . -type f -name "*.o") $(OBJ_DIR)

collect_heades:
	rm -rf $(HDR_DIR)
	mkdir $(HDR_DIR)
	cp $$(find . -type f -name "*.h") $(HDR_DIR)

link_obj:
	cd $(OBJ_DIR); $(CC)  *.o -o $(PROJECT_NAME) $(LINK_FLAGS)
	rm -rf $(BIN_DIR); mkdir $(BIN_DIR); mv $(OBJ_DIR)$(PROJECT_NAME) $(BIN_DIR)

clean:
	rm -rf ./$(OBJ_DIR)/
	rm -rf ./$(HDR_DIR)/
	rm -rf $$(find . -type f -name "*.o")
	rm -rf $(PROJECT_NAME)

run:
	$(ROOT_DIR)$(BIN_DIR)$(PROJECT_NAME)

debug:
	$(DEBUGER) $(DEBUG_FLAGS) $(ROOT_DIR)$(BIN_DIR)$(PROJECT_NAME)