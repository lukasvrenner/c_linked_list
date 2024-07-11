project('something', 'c', default_options : ['warning_level=3', 'werror=true'])
add_project_arguments('-Werror=all', language : 'c')
sources = []
subdir('src')
executable('something', 'src/main.c')
