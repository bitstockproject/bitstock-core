
Debian
====================
This directory contains files used to package bitstockd/bitstock-qt
for Debian-based Linux systems. If you compile bitstockd/bitstock-qt yourself, there are some useful files here.

## bitstock: URI support ##


bitstock-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bitstock-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bitstock-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitstock128.png` to `/usr/share/pixmaps`

bitstock-qt.protocol (KDE)

