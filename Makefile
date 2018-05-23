


all: build

build:
	cd src/ && /home/jvalka/Qt/5.5/gcc_64/bin/qmake blockeditor.pro && make -f qtMakefile
	
doxygen:
	cd src && doxygen

pack:
	zip -r ./xestva00-xvalka03.zip Makefile src doc README.txt examples

clean:
	cd src && rm *.o && rm qtMakefile && rm moc_mainwindow.cpp && rm blockeditor && rm ui_mainwindow.h
	cd doc && rm -f *

run:
	./src/blockeditor
	
