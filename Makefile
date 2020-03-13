##
## EPITECH PROJECT, 2020
## Skill or Die
## File description:
## Makefile
##

NAME		=	Skill\ or\ Die

CC		=	g++

SRCDIR		=	Src/
ETYDIR		=	$(SRCDIR)Entity/
CTLDIR		=	$(SRCDIR)Control/
EAIDIR		=	$(SRCDIR)EnemyAI/
SFPDIR		=	$(SRCDIR)SFML++/
INCDIR		=	Include/

SRC		=	$(SRCDIR)Main.cpp \
			$(SRCDIR)Game.cpp \
			$(SRCDIR)GameObject.cpp \
			$(SRCDIR)TimeFactor.cpp \
			$(SRCDIR)Input.cpp \
			$(SRCDIR)Error.cpp \
			$(ETYDIR)Entity.cpp \
			$(ETYDIR)Player.cpp \
			$(ETYDIR)Enemy.cpp \
			$(CTLDIR)AControl.cpp \
			$(CTLDIR)Control.cpp \
			$(CTLDIR)PlayerControl.cpp \
			$(EAIDIR)EnemyAIFire.cpp \
			$(SFPDIR)ConvexShapeIntersects.cpp \

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-I $(INCDIR)
CXXFLAGS	+=	-W -Wall -Wextra

LDFLAGS		+=	-l sfml-system
LDFLAGS		+=	-l sfml-window
LDFLAGS		+=	-l sfml-graphics
LDFLAGS		+=	-l sfml-audio

%.o		:	%.cpp
			@$(CC) -c -o $@ $< $(CXXFLAGS)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			@rm -f $(OBJ)

fclean		:	clean
			@rm -f $(NAME)

re		:	fclean all

debug		:	CXXFLAGS += -g3
debug		:	re
