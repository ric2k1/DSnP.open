util.d: ../../include/util.h ../../include/rnGen.h ../../include/myUsage.h ../../include/myHashSet.h ../../include/myMinHeap.h 
../../include/util.h: util.h
	@rm -f ../../include/util.h
	@ln -fs ../src/util/util.h ../../include/util.h
../../include/rnGen.h: rnGen.h
	@rm -f ../../include/rnGen.h
	@ln -fs ../src/util/rnGen.h ../../include/rnGen.h
../../include/myUsage.h: myUsage.h
	@rm -f ../../include/myUsage.h
	@ln -fs ../src/util/myUsage.h ../../include/myUsage.h
../../include/myHashSet.h: myHashSet.h
	@rm -f ../../include/myHashSet.h
	@ln -fs ../src/util/myHashSet.h ../../include/myHashSet.h
../../include/myMinHeap.h: myMinHeap.h
	@rm -f ../../include/myMinHeap.h
	@ln -fs ../src/util/myMinHeap.h ../../include/myMinHeap.h
