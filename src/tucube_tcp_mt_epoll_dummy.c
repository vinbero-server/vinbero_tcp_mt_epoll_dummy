#include <dlfcn.h>
#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <tucube/tucube_Module.h>
#include <tucube/tucube_IModule.h>
#include <tucube/tucube_ITLocal.h>
#include <tucube/tucube_ICLocal.h>
#include <tucube/tucube_IClService.h>
#include <libgenc/genc_Tree.h>

struct tucube_dummy_LocalModule {
    const char* message;
    int interval;
};

TUCUBE_ITLOCAL_FUNCTIONS;
TUCUBE_ICLOCAL_FUNCTIONS;
TUCUBE_ICLSERVICE_FUNCTIONS;

int tucube_IModule_init(struct tucube_Module* module, struct tucube_Config* config, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    module->name = "tucube_tcp_mt_epoll_dummy";
    module->version = "0.0.1";
    module->localModule.pointer = malloc(1 * sizeof(struct tucube_dummy_LocalModule));

    struct tucube_dummy_LocalModule* localModule = module->localModule.pointer;
    TUCUBE_CONFIG_GET(config, module, "tucube_dummy.message", string, &(localModule->message), "I HAVE NOTHING TO SAY");
    TUCUBE_CONFIG_GET(config, module, "tucube_dummy.interval", integer, &(localModule->interval), 1);

    struct tucube_Module_Ids childModuleIds;
    GENC_ARRAY_LIST_INIT(&childModuleIds);
    TUCUBE_CONFIG_GET_CHILD_MODULE_IDS(config, module->id, &childModuleIds);
    return 0;
}

int tucube_IModule_rInit(struct tucube_Module* module, struct tucube_Config* config, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ITLocal_init(struct tucube_Module* module, struct tucube_Config* config, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ITLocal_rInit(struct tucube_Module* module, struct tucube_Config* config, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ICLocal_init(struct tucube_Module* module, struct tucube_ClData* clData, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_IClService_call(struct tucube_Module* module, struct tucube_ClData* clData, void* args[]) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ICLocal_destroy(struct tucube_Module* module, struct tucube_ClData* clData) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ICLocal_rDestroy(struct tucube_Module* module, struct tucube_ClData* clData) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ITLocal_destroy(struct tucube_Module* module) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_ITLocal_rDestroy(struct tucube_Module* module) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_IModule_destroy(struct tucube_Module* module) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int tucube_IModule_rDestroy(struct tucube_Module* module) {
warnx("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    struct tucube_dummy_LocalModule* localModule = module->localModule.pointer;
    GENC_TREE_NODE_FOR_EACH_CHILD(module, index) {
        struct tucube_Module* childModule = &GENC_TREE_NODE_GET_CHILD(module, index);
        free(childModule->interface);
    }
    free(module->localModule.pointer);
    if(module->tlModuleKey != NULL)
        free(module->tlModuleKey);
//    dlclose(module->dl_handle);
    return 0;
}


