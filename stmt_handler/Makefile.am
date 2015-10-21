AM_CPPFLAGS= -fPIC -fpermissive \
-I${HADOOP_HOME}/src/c++/libhdfs\
-I${JAVA_HOME}/include\
-I${JAVA_HOME}/include/linux \
-I${THERON_HOME}/Include \
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/serialization

AM_LDFLAGS=-lc -lm -lrt -lboost_system -lboost_serialization -ll -ly -lstdc++ -lxs

if OPT_TCMALLOC
AM_CPPFLAGS+=-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
AM_LDFLAGS+=-ltcmalloc 
endif

LDADD = ../Catalog/libcatalog.a \
		../Catalog/stat/libstat.a \
		../LogicalQueryPlan/liblogicalqueryplan.a \
		../Loader/libloader.a \
		../BlockStreamIterator/ParallelBlockStreamIterator/libparallelblockstreamiterator.a \
		../common/libcommon.a \
		../common/Expression/libexpression.a \
		../utility/libutility.a \
		../sql_parser/ast_node/libast_node.a \
		../sql_parser/parser/libparser.a \
		${BOOST_HOME}/stage/lib/libboost_system.a \
		${BOOST_HOME}/stage/lib/libboost_system.so \
		${BOOST_HOME}/stage/lib/libboost_serialization.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.a

noinst_LIBRARIES=libstmthandler.a

libstmthandler_a_SOURCES = \
	stmt_handler.cpp	stmt_handler.h	\
	stmt_exec.cpp	stmt_exec.h \
	select_exec.cpp	select_exec.h \
	insert_exec.cpp insert_exec.h \
	load_exec.cpp	load_exec.h \
	create_exec.cpp create_exec.h
	

	