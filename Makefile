MAKE = make
SUBDIR = "src"
FILENAME="input.xml"

all:
	$(MAKE) -C $(SUBDIR)

run:
	$(MAKE) run FILENAME="../$(FILENAME)" -C $(SUBDIR)

clean:
	$(MAKE) clean -C $(SUBDIR)
