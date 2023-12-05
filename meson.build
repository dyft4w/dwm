# Name, Language
project('dwm','c')
version='6.4'
# Files
src=['dwm.c','drw.c','util.c']
# Dependencies (x11, xfreetype)
x11_dep = [dependency('x11'),dependency('freetype2'),dependency('xft'),dependency('fontconfig')]
#others (ugly ahh hell ik ik), Wno-d-d is in the OG Makefile
add_project_arguments(['-DVERSION="'+version+'"','-Wno-deprecated-declarations'],language : 'c')

executable('dwm',
            src,
            dependencies : x11_dep)
