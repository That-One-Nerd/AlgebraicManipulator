# ----------------------------
# Makefile Options
# ----------------------------

NAME = ALGEBRA
ICON = icon.png
DESCRIPTION = "Algebraic Manipulator v0.0.0"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
