TEMPLATE = subdirs
SUBDIRS = src

icons.extra = cp icons/meego/100x100.png rfk.png
icons.path = $$target.path/usr/share/icons
icons.files = rfk.png
INSTALLS += icons

desktop.path = $$target.path/usr/share/applications
desktop.files = rfk.desktop
INSTALLS += desktop

rfk.path = $$target.path/usr/bin
rfk.files = src/rfk
INSTALLS += rfk



