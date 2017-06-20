
#
# Makefile for RPC 
#

# Default application name (overide with make APP=toto all)

APP = index

# written by developer

 $(APP).c -> $(APP) 	client
 $(APP)_local.c	processing functions

# compiled by rpcgen

 $(APP)_svc.c		server
 $(APP)_clnt.c		client
 $(APP).h		common header
 $(APP)_xdr.c		xdr filters

 Linux CFLAGS
CFLAGS = -g

 LDFLAGS = -lcurses

# Remote app
all: $(APP) $(APP)_svc 

 Local app test: make one binary linking index.o & index_local.o
local: $(APP)_local

###############################################################################
#                               rpcgen

$(APP)_xdr.c : $(APP).x
	rpcgen -c $(APP).x > $@

$(APP)_svc.c : $(APP).x
	rpcgen -s udp -s tcp $(APP).x > $@
$(APP)_clnt.c : $(APP).x
	rpcgen -l $(APP).x > $@

$(APP).h : $(APP).x
	rpcgen -h $(APP).x > $@

# client 

$(APP) : $(APP).h $(APP)_xdr.o $(APP).o $(APP)_clnt.o
	$(CC) $(CFLAGS) -o $@ $(APP)_xdr.o $(APP).o $(APP)_clnt.o

# server

$(APP)_svc: $(APP).h $(APP)_local.o  $(APP)_xdr.o $(APP)_svc.o
	$(CC) $(CFLAGS) -o $@ $(APP)_local.o  $(APP)_xdr.o $(APP)_svc.o

###############################################################################
#                          local application 

$(APP)_local : $(APP)_local.o $(APP).o $(APP).h 
	$(CC) $(CFLAGS) -o $@ $(APP)_local.o $(APP).o

###############################################################################
#                               clean

clean :
	\rm -f $(APP)_xdr.o $(APP)_svc.o $(APP)_clnt.o $(APP)_local.o $(APP).o

bigclean :
	\rm -f $(APP)_xdr.o $(APP)_svc.o $(APP)_clnt.o $(APP)_local.o $(APP)_xdr.c $(APP)_svc.c $(APP)_clnt.c $(APP).o $(APP).h $(APP) $(APP)_svc


