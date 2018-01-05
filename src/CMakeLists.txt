add_library(tucube_tcp_mt_epoll_dummy MODULE tucube_tcp_mt_epoll_dummy.c)
set_target_properties(tucube_tcp_mt_epoll_dummy PROPERTIES PREFIX "")
set_target_properties(tucube_tcp_mt_epoll_dummy PROPERTIES PUBLIC_HEADER "")
install(TARGETS tucube_tcp_mt_epoll_dummy
        LIBRARY DESTINATION lib/tucube
        PUBLIC_HEADER DESTINATION include/tucube)
