db.d: ../../include/dbJson.h 
../../include/dbJson.h: dbJson.h
	@rm -f ../../include/dbJson.h
	@ln -fs ../src/db/dbJson.h ../../include/dbJson.h
