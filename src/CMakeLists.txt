add_library(vinbero_tcp_mt_epoll_dummy MODULE vinbero_tcp_mt_epoll_dummy.c)
set_target_properties(vinbero_tcp_mt_epoll_dummy PROPERTIES PREFIX "")
set_target_properties(vinbero_tcp_mt_epoll_dummy PROPERTIES PUBLIC_HEADER "")
install(TARGETS vinbero_tcp_mt_epoll_dummy
        LIBRARY DESTINATION lib/vinbero
        PUBLIC_HEADER DESTINATION include/vinbero)
