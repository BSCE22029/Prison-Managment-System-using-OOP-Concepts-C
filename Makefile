all: ./a.out

compRun:

	g++ -std=c++11 main.cpp calling.cpp case.cpp civilian.cpp court.cpp criminal.cpp evidence.cpp forensic_laboratory.cpp judge.cpp lawyer.cpp person.cpp police_officer.cpp police_station.cpp prisoner.cpp police_head.cpp Punishment.cpp victim.cpp Visitor.cpp -o r.out

compTest:
	g++ -std=c++11 test.cpp policestation.cpp -o a.out

test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
