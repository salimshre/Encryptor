


#to run this command

g++ main.cpp user_interface.cpp core/encryption.cpp core/history.cpp ui/animations.cpp ui/helpers.cpp ^
  -o encryption_defence ^
  -lbgi -lgdi32 -lwinmm -lcomdlg32 -lole32 -loleaut32 -luuid
