compile:
	gcc src/main.c src/jt_perm.c -o jt_perm
exec: compile
	./jt_perm
