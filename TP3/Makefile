
SubMakeDirs    = $(shell ls -d */)

all::
	@for dir in $(SubMakeDirs); do \
            $(MAKE) -C $$dir $@ || exit $$?; \
        done

