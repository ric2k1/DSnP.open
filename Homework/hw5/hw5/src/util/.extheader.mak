util.d: ../../include/util.h ../../include/rnGen.h ../../include/myUsage.h ../../include/dlist.h ../../include/array.h ../../include/bst.h 
../../include/util.h: util.h
	@rm -f ../../include/util.h
	@ln -fs ../src/util/util.h ../../include/util.h
../../include/rnGen.h: rnGen.h
	@rm -f ../../include/rnGen.h
	@ln -fs ../src/util/rnGen.h ../../include/rnGen.h
../../include/myUsage.h: myUsage.h
	@rm -f ../../include/myUsage.h
	@ln -fs ../src/util/myUsage.h ../../include/myUsage.h
../../include/dlist.h: dlist.h
	@rm -f ../../include/dlist.h
	@ln -fs ../src/util/dlist.h ../../include/dlist.h
../../include/array.h: array.h
	@rm -f ../../include/array.h
	@ln -fs ../src/util/array.h ../../include/array.h
../../include/bst.h: bst.h
	@rm -f ../../include/bst.h
	@ln -fs ../src/util/bst.h ../../include/bst.h
