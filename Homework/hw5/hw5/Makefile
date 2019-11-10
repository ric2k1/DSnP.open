REFPKGS  = cmd
SRCPKGS  = util
LIBPKGS  = $(REFPKGS) $(SRCPKGS)
MAIN     = main

LIBS     = $(addprefix -l, $(LIBPKGS))
SRCLIBS  = $(addsuffix .a, $(addprefix lib, $(SRCPKGS)))

dummy:
	@echo "Error: please use make <d | a | b | linux16 | linux18 | clean | cleanall | ctags>"

.PHONY : d a b

d: ADT   = dlist
a: ADT   = array
b: ADT   = bst

d: ADTFLAG = -DTEST_DLIST
a: ADTFLAG = -DTEST_ARRAY
b: ADTFLAG = -DTEST_BST

d a b: clean clean all

EXEC     = adtTest.$(ADT)

all: libs main

libs:
	@for pkg in $(SRCPKGS); \
	do \
		echo "Checking $$pkg..."; \
		cd src/$$pkg; \
                make -f make.$$pkg --no-print-directory PKGNAME=$$pkg; \
		cd ../..; \
	done

main:
	@echo "Checking $(MAIN)..."
	@cd src/$(MAIN); \
		make -f make.$(MAIN) --no-print-directory ADTFLAG=$(ADTFLAG) \
		                          INCLIB="$(LIBS)" EXEC=$(EXEC);
	@ln -fs bin/$(EXEC) .
#	@strip bin/$(EXEC)

clean:
	@for pkg in $(SRCPKGS); \
	do \
		echo "Cleaning $$pkg..."; \
		cd src/$$pkg; \
                make -f make.$$pkg --no-print-directory PKGNAME=$$pkg clean; \
                cd ../..; \
	done
	@echo "Cleaning $(MAIN)..."
	@cd src/$(MAIN); make -f make.$(MAIN) --no-print-directory clean
	@echo "Removing $(SRCLIBS)..."
	@cd lib; rm -f $(SRCLIBS)
	@echo "Removing $(EXEC)..."
	@rm -rf bin/$(EXEC)*

cleanall: clean
	@echo "Removing bin/*..."
	@rm -rf bin/*

ctags:	  
	@rm -f src/tags
	@for pkg in $(SRCPKGS) main; \
	do \
		echo "Tagging $$pkg..."; \
		cd src; ctags -a $$pkg/*.cpp $$pkg/*.h; cd ..; \
	done
	@echo "Tagging $(MAIN)..."
	@cd src; ctags -a $(MAIN)/*.cpp $(MAIN)/*.h

linux18 mac:
	@for pkg in $(REFPKGS); \
	do \
	        cd lib; ln -sf lib$$pkg-$@.a lib$$pkg.a; cd ..; \
	done
	@cd ref; ln -sf adtTest-$@.dlist adtTest.dlist; \
	         ln -sf adtTest-$@.array adtTest.array; \
	         ln -sf adtTest-$@.bst   adtTest.bst

