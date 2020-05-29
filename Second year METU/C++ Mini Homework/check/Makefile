1:
	g++ -std=c++11 TestGroup1.cpp Book.cpp HardCopy.cpp SoftCopy.cpp -o test;
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test;
2:
	g++ -std=c++11 TestGroup2.cpp Book.cpp  SoftCopy.cpp -o test;
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test;
4:
	g++ -std=c++11 TestGroup4.cpp Book.cpp  SoftCopy.cpp -o test -ggdb3;
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s  ./test;
5:
	g++ -std=c++11 TestGroup5.cpp Book.cpp  SoftCopy.cpp -o test -ggdb3;
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s  ./test;
3:
	g++ -std=c++11 TestGroup3.cpp Book.cpp  SoftCopy.cpp -o test -ggdb3;
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s  ./test;
check:
	g++ -std=c++11 tgall.cpp Book.cpp HardCopy.cpp SoftCopy.cpp -o test && ./test;