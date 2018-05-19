#include <dlfcn.h>
#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vinbero_common/vinbero_common_Config.h>
#include <vinbero_common/vinbero_common_Log.h>
#include <vinbero_common/vinbero_common_Module.h>
#include <vinbero/vinbero_IModule.h>
#include <vinbero/vinbero_ITLocal.h>
#include <vinbero/vinbero_ICLocal.h>
#include <vinbero/vinbero_IClService.h>
#include <libgenc/genc_Tree.h>
#include <gaio.h>

struct vinbero_tcp_mt_epoll_dummy_ClData {
    int* clientSocket;
};

VINBERO_ITLOCAL_FUNCTIONS;
VINBERO_ICLOCAL_FUNCTIONS;
VINBERO_ICLSERVICE_FUNCTIONS;

int vinbero_IModule_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    module->name = "vinbero_tcp_mt_epoll_dummy";
    module->version = "0.0.1";
    module->needsChildren = false;
    return 0;
}

int vinbero_IModule_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ICLocal_init(struct vinbero_common_Module* module, struct vinbero_ClData* clData, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    clData->generic.pointer = args[0];
    return 0;
}

int vinbero_IClService_call(struct vinbero_common_Module* module, struct vinbero_ClData* clData, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    struct gaio_Io* clientIo = clData->generic.pointer;
    clientIo->methods->write(clientIo, "HTTP/1.1 200 OK\r\nContent-Length:5\r\n\r\nHELLO", sizeof("HTTP/1.1 200 OK\r\nContent-Length:5\r\n\r\nHELLO") - 1);
    return 0;
}

int vinbero_ICLocal_destroy(struct vinbero_common_Module* module, struct vinbero_ClData* clData) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ICLocal_rDestroy(struct vinbero_common_Module* module, struct vinbero_ClData* clData) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_rDestroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_IModule_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_IModule_rDestroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    struct vinbero_dummy_LocalModule* localModule = module->localModule.pointer;
    free(module->localModule.pointer);
    if(module->tlModuleKey != NULL)
        free(module->tlModuleKey);
//    dlclose(module->dl_handle);
    return 0;
}


