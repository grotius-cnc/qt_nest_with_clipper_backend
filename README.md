# QT_Nest_with_clipper_backend
QT gui with 2d plate nesting algoritmme. The backend is configured for clipper in this upload.

The test input is a box of 100x100mm.

In the Mainwindow.cpp we have a test box that is nested in total 3+1 times.
Keep the contour input clockwise cw.
The input startpoint must be the same as the input endpoint.

   std::vector<Item> input1(3, //this means nest the box 3 times.
    {
                                 {0, 0},    //box start
                                 {0, 100},
                                 {100, 100},
                                 {100, 0},
                                 {0, 0},    //box end=start

                             });

Nesting output :
![alt text](https://raw.githubusercontent.com/grotius-cnc/QT_Nest_with_clipper_backend/master/nest_test.png)

Installation guide for 2 dependencies, when you have problems.
If the make fails, start again with a clean directory.

This project is a orginal git clone off : https://github.com/tamasmeszaros/libnest2d.git

for the nlopt library :

documentation : https://nlopt.readthedocs.io/en/latest/NLopt_Installation/

1. git clone https://github.com/stevengj/nlopt.git
2. in the nlopt directory open terminal :

cmake -DCMAKE_INSTALL_PREFIX=/home/user/QT_Nest/nlopt/   "change to your directory adres"
make
make install


for the clipper library :

download the zip from : https://sourceforge.net/projects/polyclipping/

1.unzip the package.
2.cd cpp
3.in terminal :

cmake -DCMAKE_INSTALL_PREFIX=/home/user/QT_Nest/clipper/  "change to your directory adres"
make
make install

Link the libraries in the qt .pro file like :
LIBS +=	-L$$PWD/clipper/ -lpolyclipping \
        -L$$PWD/nlopt/ -lnlopt
        
The nesting program is tested on Debian 10, with QT installation :
Qt Creator 4.12.3,
Based on Qt 5.14.2 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6), 64 bit)
Built on Jun 16 2020 04:15:35
From revision 48e46132e3
