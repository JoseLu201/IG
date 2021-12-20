HEADERS += \
  beak.h \
  body1.h \
  body_head.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cone_sectioned.h \
  cube.h \
  cylinder.h \
  eje.h \
  file_ply_stl.h \
  head.h \
  head_complete.h \
  object3d.h \
  axis.h \
  ply.h \
  revolution_objetct.h \
  revolution_ply.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  wheel.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  beak.cc \
  body1.cpp \
  body_head.cc \
  cone.cc \
  cone_sectioned.cc \
  cube.cc \
  cylinder.cc \
  eje.cc \
  file_ply_stl.cc \
  head.cc \
  head_complete.cc \
  object3d.cc \
  axis.cc \
  ply.cc \
  revolution_objetct.cc \
  revolution_ply.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  wheel.cc \
  window.cc


LIBS += -lopengl32

CONFIG += c++11
QT += widgets opengl
