# Go one level deeper for the code.
SUBDIRS = src

# Package the readme with the project.
dist_doc_DATA = README.md

# Set the relevant paths for binaries and units.
rootbindir=$(DESTDIR)$(bindir)
systemunitdir=$(DESTDIR)$(libdir)/systemd/system

EXTRA_DIST = units/sadaemon.service.in units/sadaemon.socket.in

# Substitute the @rootbindir@ placeholder in the unit files with real paths.
substitutions = \
	'|rootbindir=$(rootbindir)|'

SED_PROCESS = \
	$(AM_V_GEN)$(MKDIR_P) $(dir $@) && \
	$(SED) $(subst '|,-e 's|@,$(subst =,\@|,$(subst |',|g',$(substitutions)))) \
		< $< > $@

units/%: units/%.in
	$(SED_PROCESS)

nodist_systemunit_DATA = units/sadaemon.service units/sadaemon.socket

install-exec-hook: $(INSTALL_EXEC_HOOKS)

uninstall-hook: $(UNINSTALL_DATA_HOOKS) $(UNINSTALL_EXEC_HOOKS)

install-data-hook: $(INSTALL_DATA_HOOKS)
