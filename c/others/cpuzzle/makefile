all: c84
c84:
	gcc c84.c linkfunc.c -o c84.exe
	./c84.exe
c85:
	gcc delete.c letter.c display.c input.c -o c85.exe
	./c85.exe
c86:
	gcc record.c save_load.c add_disp.c delete_record.c -o c86.exe
	./c86.exe
## c87 doesn't work
c87:
	gcc student.c student_add_disp.c sav_load.c quee_remv_modi.c -o c87.exe
	./c87.exe
## c103 doesn't work
c103:
	gcc air.c airfight.c -o airfight.exe
	./airfight.exe
## c104 doesn't work
c104:
	gcc snake.c -o snake.exe
	./snake.exe
c105:
	gcc park1.c park.c -o park.exe
	./park.exe
.PHONY: clean
clean:
	rm -f *.exe *.log

