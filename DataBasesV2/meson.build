project('DataBasesV2', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

qt6 = import('qt6')
qt6_dep = dependency('qt6', modules : ['Core', 'Widgets'])

ui_sources = [
    'mainwindow.ui',
    'gpu_window.ui',
    'cpu_window.ui',
    'ram_window.ui',
]

main_ui = qt6.compile_ui(sources : ui_sources)

moc_files = qt6.compile_moc(headers : ['dbview.h', 'editorwidget.h', 'cpuwidget.h', 'ramwidget.h'],
    dependencies : qt6_dep)

sources = [
    'main.cpp',
    'dbview.cpp',
    'computerpart.cpp',
    'gpu.cpp',
    'editorwidget.cpp',
    'cpu.cpp',
    'ram.cpp',
    'cpuwidget.cpp'
]

executable('DataBasesV2', sources, main_ui, moc_files,
    dependencies : qt6_dep,
    install : true)
