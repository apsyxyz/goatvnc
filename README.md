goatvnc
=======
goatse script kiddies looking for easy shells. :)

Build
-----

It requires libvncserver and libgd.
Compiles with just `make` on OSX, to get it to build on FreeBSD I had to do:
    cc goatvnc.c /usr/local/lib/libgd.so /usr/local/lib/libvncserver.so -I /usr/local/include -o goatvnc

Licence
-------
    Copyright © 2016 @apsyxyz
    This work is free. You can redistribute it and/or modify it under the
    terms of the Do What The Fuck You Want To Public License, Version 2,
    as published by Sam Hocevar. See the COPYING file for more details.
