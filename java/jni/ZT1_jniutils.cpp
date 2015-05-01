#include "ZT1_jniutils.h"
#include <string>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

jobject createResultObject(JNIEnv *env, ZT1_ResultCode code)
{
    jclass resultClass = NULL;
    
    jobject resultObject = NULL;

    resultClass = env->FindClass("com/zerotierone/sdk/ResultCode");
    if(resultClass == NULL)
    {
        return NULL; // exception thrown
    }

    std::string fieldName;
    switch(code)
    {
    case ZT1_RESULT_OK:
        fieldName = "RESULT_OK";
        break;
    case ZT1_RESULT_FATAL_ERROR_OUT_OF_MEMORY:
        fieldName = "RESULT_FATAL_ERROR_OUT_OF_MEMORY";
        break;
    case ZT1_RESULT_FATAL_ERROR_DATA_STORE_FAILED:
        fieldName = "RESULT_FATAL_ERROR_DATA_STORE_FAILED";
        break;
    case ZT1_RESULT_ERROR_NETWORK_NOT_FOUND:
        fieldName = "RESULT_ERROR_NETWORK_NOT_FOUND";
        break;
    case ZT1_RESULT_FATAL_ERROR_INTERNAL:
    default:
        fieldName = "RESULT_FATAL_ERROR_INTERNAL";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(resultClass, fieldName.c_str(), "Lcom/zerotierone/sdk/ResultCode;");

    resultObject = env->GetStaticObjectField(resultClass, enumField);

    return resultObject;
}


jobject createVirtualNetworkStatus(JNIEnv *env, ZT1_VirtualNetworkStatus status)
{
    jclass statusClass = NULL;
    jobject statusObject = NULL;

    if(statusClass == NULL)
    {
        statusClass = env->FindClass("com/zerotierone/sdk/VirtualNetworkStatus");
        if(statusClass == NULL)
        {
            return NULL; // exception thrown
        }
    }

    std::string fieldName;
    switch(status)
    {
    case ZT1_NETWORK_STATUS_REQUESTING_CONFIGURATION:
        fieldName = "NETWORK_STATUS_REQUESTING_CONFIGURATION";
        break;
    case ZT1_NETWORK_STATUS_OK:
        fieldName = "NETWORK_STATUS_OK";
        break;
    case ZT1_NETWORK_STATUS_ACCESS_DENIED:
        fieldName = "NETWORK_STATUS_ACCESS_DENIED";
        break;
    case ZT1_NETWORK_STATUS_NOT_FOUND:
        fieldName = "NETWORK_STATUS_NOT_FOUND";
        break;
    case ZT1_NETWORK_STATUS_PORT_ERROR:
        fieldName = "NETWORK_STATUS_PORT_ERROR";
        break;
    case ZT1_NETWORK_STATUS_CLIENT_TOO_OLD:
        fieldName = "NETWORK_STATUS_CLIENT_TOO_OLD";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(statusClass, fieldName.c_str(), "Lcom/zerotierone/sdk/VirtualNetworkStatus;");

    statusObject = env->GetStaticObjectField(statusClass, enumField);

    return statusObject;
}

jobject createEvent(JNIEnv *env, ZT1_Event event)
{
    jclass eventClass = NULL;
    jobject eventObject = NULL;

    eventClass = env->FindClass("com/zerotierone/sdk/Event");
    if(eventClass == NULL)
    {
        return NULL;
    }

    std::string fieldName;
    switch(event)
    {
    case ZT1_EVENT_UP:
        fieldName = "EVENT_UP";
        break;
    case ZT1_EVENT_OFFLINE:
        fieldName = "EVENT_OFFLINE";
        break;
    case ZT1_EVENT_ONLINE:
        fieldName = "EVENT_ONLINE";
        break;
    case ZT1_EVENT_DOWN:
        fieldName = "EVENT_DOWN";
        break;
    case ZT1_EVENT_FATAL_ERROR_IDENTITY_COLLISION:
        fieldName = "EVENT_FATAL_ERROR_IDENTITY_COLLISION";
        break;
    case ZT1_EVENT_SAW_MORE_RECENT_VERSION:
        fieldName = "EVENT_SAW_MORE_RECENT_VERSION";
        break;
    case ZT1_EVENT_AUTHENTICATION_FAILURE:
        fieldName = "EVENT_AUTHENTICATION_FAILURE";
        break;
    case ZT1_EVENT_INVALID_PACKET:
        fieldName = "EVENT_INVALID_PACKET";
        break;
    case ZT1_EVENT_TRACE:
        fieldName = "EVENT_TRACE";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(eventClass, fieldName.c_str(), "Lcom/zerotierone/sdk/Event;");

    eventObject = env->GetStaticObjectField(eventClass, enumField);

    return eventObject;
}

jobject createPeerRole(JNIEnv *env, ZT1_PeerRole role)
{
    jclass peerRoleClass = NULL;
    jobject peerRoleObject = NULL;

    peerRoleClass = env->FindClass("com/zerotierone/sdk/PeerRole");
    if(peerRoleClass == NULL)
    {
        return NULL;
    }

    std::string fieldName;
    switch(role)
    {
    case ZT1_PEER_ROLE_LEAF:
        fieldName = "PEER_ROLE_LEAF";
        break;
    case ZT1_PEER_ROLE_HUB:
        fieldName = "PEER_ROLE_HUB";
        break;
    case ZT1_PEER_ROLE_SUPERNODE:
        fieldName = "PEER_ROLE_SUPERNODE";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(peerRoleClass, fieldName.c_str(), "Lcom/zerotierone/sdk/PeerRole;");

    peerRoleObject = env->GetStaticObjectField(peerRoleClass, enumField);

    return peerRoleObject;
}

jobject createVirtualNetworkType(JNIEnv *env, ZT1_VirtualNetworkType type)
{
    jclass vntypeClass = NULL;
    jobject vntypeObject = NULL;

    vntypeClass = env->FindClass("com/zerotierone/sdk/VirtualNetworkType");
    if(vntypeClass == NULL)
    {
        return NULL;
    }

    std::string fieldName;
    switch(type)
    {
    case ZT1_NETWORK_TYPE_PRIVATE:
        fieldName = "NETWORK_TYPE_PRIVATE";
        break;
    case ZT1_NETWORK_TYPE_PUBLIC:
        fieldName = "NETWORK_TYPE_PUBLIC";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(vntypeClass, fieldName.c_str(), "Lcom/zerotierone/sdk/VirtualNetworkType;");
    vntypeObject = env->GetStaticObjectField(vntypeClass, enumField);
    return vntypeObject;
}

jobject createVirtualNetworkConfigOperation(JNIEnv *env, ZT1_VirtualNetworkConfigOperation op)
{
    jclass vnetConfigOpClass = NULL;
    jobject vnetConfigOpObject = NULL;

    vnetConfigOpClass = env->FindClass("com/zerotierone/sdk/VirtualNetworkConfigOperation");
    if(vnetConfigOpClass == NULL)
    {
        return NULL;
    }

    std::string fieldName;
    switch(op)
    {
    case ZT1_VIRTUAL_NETWORK_CONFIG_OPERATION_UP:
        fieldName = "VIRTUAL_NETWORK_CONFIG_OPERATION_UP";
        break;
    case ZT1_VIRTUAL_NETWORK_CONFIG_OPERATION_CONFIG_UPDATE:
        fieldName = "VIRTUAL_NETWORK_CONFIG_OPERATION_CONFIG_UPDATE";
        break;
    case ZT1_VIRTUAL_NETWORK_CONFIG_OPERATION_DOWN:
        fieldName = "VIRTUAL_NETWORK_CONFIG_OPERATION_DOWN";
        break;
    case ZT1_VIRTUAL_NETWORK_CONFIG_OPERATION_DESTROY:
        fieldName = "VIRTUAL_NETWORK_CONFIG_OPERATION_DESTROY";
        break;
    }

    jfieldID enumField = env->GetStaticFieldID(vnetConfigOpClass, fieldName.c_str(), "Lcom/zerotierone/sdk/VirtualNetworkConfigOperation;");
    vnetConfigOpObject = env->GetStaticObjectField(vnetConfigOpClass, enumField);
    return vnetConfigOpObject;
}

jobject newArrayList(JNIEnv *env)
{
    jclass arrayListClass = NULL;
    jmethodID arrayList_constructor = NULL;

    arrayListClass = env->FindClass("java/util/ArrayList");
    if(arrayListClass == NULL)
    {
        return NULL;
    }

    arrayList_constructor = env->GetMethodID(
        arrayListClass, "<init>", "()V");
    if(arrayList_constructor == NULL)
    {
        return NULL;
    }

    jobject arrayListObj = env->NewObject(arrayListClass, arrayList_constructor);

    return arrayListObj;
}

bool appendItemToArrayList(JNIEnv *env, jobject array, jobject object)
{
    assert(array != NULL);
    assert(object != NULL);

    jclass arrayListClass = NULL;
    jmethodID arrayList_add = NULL;

    arrayListClass = env->FindClass("java/util/ArrayList");
    if(arrayListClass == NULL)
    {
        return NULL;
    }

    arrayList_add = env->GetMethodID(arrayListClass, "add", "(Ljava.lang.Object;)Z");
    if(arrayList_add == NULL)
    {
        return false;
    }

    return env->CallBooleanMethod(array, arrayList_add, object);
}

jobject newInetAddress(JNIEnv *env, const sockaddr_storage &addr)
{
    jclass inetAddressClass = NULL;
    jmethodID inetAddress_getByAddress = NULL;

    inetAddressClass = env->FindClass("java/net/InetAddress");
    if(inetAddressClass == NULL)
    {
        return NULL;
    }

    inetAddress_getByAddress = env->GetStaticMethodID(
        inetAddressClass, "getByAddress", "([B)Ljava/net/InetAddress;");
    if(inetAddress_getByAddress == NULL)
    {
        return NULL;
    }

    jobject inetAddressObj = NULL;
    switch(addr.ss_family)
    {
        case AF_INET6:
        {
            sockaddr_in6 *ipv6 = (sockaddr_in6*)&addr;
            jbyteArray buff = env->NewByteArray(16);
            if(buff == NULL)
            {
                return NULL;
            }

            env->SetByteArrayRegion(buff, 0, 16, (jbyte*)ipv6->sin6_addr.s6_addr);
            inetAddressObj = env->CallStaticObjectMethod(
                inetAddressClass, inetAddress_getByAddress, buff);
        }
        break;
        case AF_INET:
        {
            sockaddr_in *ipv4 = (sockaddr_in*)&addr;
            jbyteArray buff = env->NewByteArray(4);
            if(buff == NULL)
            {
                return NULL;
            }

            env->SetByteArrayRegion(buff, 0, 4, (jbyte*)&ipv4->sin_addr);
            inetAddressObj = env->CallStaticObjectMethod(
                inetAddressClass, inetAddress_getByAddress, buff);
        }
        break;
    }

    return inetAddressObj;
}

jobject newInetSocketAddress(JNIEnv *env, const sockaddr_storage &addr)
{
    jclass inetSocketAddressClass = NULL;
    jmethodID inetSocketAddress_constructor = NULL;

    inetSocketAddressClass = env->FindClass("java/net/InetSocketAddress");
    if(inetSocketAddressClass == NULL)
    {
        return NULL;
    }

    jobject inetAddressObject = newInetAddress(env, addr);

    if(inetAddressObject == NULL)
    {
        return NULL;
    }

    inetSocketAddress_constructor = env->GetMethodID(
        inetSocketAddressClass, "<init>", "(Ljava/net/InetAddress;I)V");
    if(inetSocketAddress_constructor == NULL)
    {
        return NULL;
    }

    int port = 0;
    switch(addr.ss_family)
    {
        case AF_INET6:
        {
            sockaddr_in6 *ipv6 = (sockaddr_in6*)&addr;
            port = ntohs(ipv6->sin6_port);
        }
        break;
        case AF_INET:
        {
            sockaddr_in *ipv4 = (sockaddr_in*)&addr;
            port = ntohs(ipv4->sin_port);
        }
        break;
    };

    jobject inetSocketAddressObject = env->NewObject(inetSocketAddressClass, inetSocketAddress_constructor, inetAddressObject, port);
    return inetSocketAddressObject;
}

jobject newMulticastGroup(JNIEnv *env, const ZT1_MulticastGroup &mc)
{
    jclass multicastGroupClass = NULL;
    jmethodID multicastGroup_constructor = NULL;

    jfieldID macField = NULL;
    jfieldID adiField = NULL;

    multicastGroupClass = env->FindClass("com/zerotierone/sdk/MulticastGroup");
    if(multicastGroupClass == NULL)
    {
        return NULL;
    }

    multicastGroup_constructor = env->GetMethodID(
        multicastGroupClass, "<init>", "()V");
    if(multicastGroup_constructor == NULL)
    {
        return NULL;
    }

    jobject multicastGroupObj = env->NewObject(multicastGroupClass, multicastGroup_constructor);
    if(multicastGroupObj == NULL)
    {
        return NULL;
    }

    if(macField == NULL)
    {
        macField = env->GetFieldID(multicastGroupClass, "mac", "J");
        if(macField == NULL)
        {
            return NULL;
        }
    }

    if(adiField == NULL)
    {
        adiField = env->GetFieldID(multicastGroupClass, "adi", "J");
        if(adiField == NULL)
        {
            return NULL;
        }
    }

    env->SetLongField(multicastGroupObj, macField, mc.mac);
    env->SetLongField(multicastGroupObj, adiField, mc.adi);

    return multicastGroupObj;
}

jobject newPeerPhysicalPath(JNIEnv *env, const ZT1_PeerPhysicalPath &ppp)
{
    jclass pppClass = NULL;

    jfieldID addressField = NULL;
    jfieldID lastSendField = NULL;
    jfieldID lastReceiveField = NULL;
    jfieldID fixedField = NULL;
    jfieldID activeField = NULL;
    jfieldID preferredField = NULL;

    jmethodID ppp_constructor = NULL;

    pppClass = env->FindClass("com/zerotierone/sdk/PeerPhysicalPath");
    if(pppClass == NULL)
    {
        return NULL;
    }

    addressField = env->GetFieldID(pppClass, "address", "Ljava/net/InetAddress;");
    if(addressField == NULL)
    {
        return NULL;
    }

    lastSendField = env->GetFieldID(pppClass, "lastSend", "J");
    if(lastSendField == NULL)
    {
        return NULL;
    }

    lastReceiveField = env->GetFieldID(pppClass, "lastReceive", "J");
    if(lastReceiveField == NULL)
    {
        return NULL;
    }

    fixedField = env->GetFieldID(pppClass, "fixed", "Z");
    if(fixedField == NULL)
    {
        return NULL;
    }

    activeField = env->GetFieldID(pppClass, "active", "Z");
    if(activeField == NULL)
    {
        return NULL;
    }

    preferredField = env->GetFieldID(pppClass, "preferred", "Z");
    if(preferredField == NULL)
    {
        return NULL;
    }

    ppp_constructor = env->GetMethodID(pppClass, "<init>", "()V");
    if(ppp_constructor == NULL)
    {
        return NULL;
    }

    jobject pppObject = env->NewObject(pppClass, ppp_constructor);
    if(pppObject == NULL)
    {
        return NULL; // out of memory
    }

    jobject addressObject = newInetAddress(env, ppp.address);

    env->SetObjectField(pppClass, addressField, addressObject);
    env->SetLongField(pppClass, lastSendField, ppp.lastSend);
    env->SetLongField(pppClass, lastReceiveField, ppp.lastReceive);
    env->SetBooleanField(pppClass, fixedField, ppp.fixed);
    env->SetBooleanField(pppClass, activeField, ppp.active);
    env->SetBooleanField(pppClass, preferredField, ppp.preferred);

    return pppObject;
}

jobject newPeer(JNIEnv *env, const ZT1_Peer &peer) 
{
    jclass peerClass = NULL;

    jfieldID addressField = NULL;
    jfieldID lastUnicastFrameField = NULL;
    jfieldID lastMulticastFrameField = NULL;
    jfieldID versionMajorField = NULL;
    jfieldID versionMinorField = NULL;
    jfieldID versionRevField = NULL;
    jfieldID latencyField = NULL;
    jfieldID roleField = NULL;
    jfieldID pathsField = NULL;

    jmethodID peer_constructor = NULL;

    peerClass = env->FindClass("com/zerotierone/sdk/Peer");
    if(peerClass == NULL)
    {
        return NULL;
    }

    addressField = env->GetFieldID(peerClass, "address", "J");
    if(addressField == NULL)
    {
        return NULL;
    }

    lastUnicastFrameField = env->GetFieldID(peerClass, "lastUnicastFrame", "J");
    if(lastUnicastFrameField == NULL)
    {
        return NULL;
    }

    lastMulticastFrameField = env->GetFieldID(peerClass, "lastMulticastFrame", "J");
    if(lastMulticastFrameField == NULL)
    {
        return NULL;
    }

    versionMajorField = env->GetFieldID(peerClass, "versionMajor", "I");
    if(versionMajorField == NULL)
    {
        return NULL;
    }

    versionMinorField = env->GetFieldID(peerClass, "versionMinor", "I");
    if(versionMinorField == NULL)
    {
        return NULL;
    }

    versionRevField = env->GetFieldID(peerClass, "versionRev", "I");
    if(versionRevField == NULL)
    {
        return NULL;
    }

    latencyField = env->GetFieldID(peerClass, "latency", "I");
    if(latencyField == NULL)
    {
        return NULL;
    }

    roleField = env->GetFieldID(peerClass, "role", "Lcom/zerotierone/sdk/PeerRole;");
    if(roleField == NULL)
    {
        return NULL;
    }

    pathsField = env->GetFieldID(peerClass, "paths", "Ljava.util.ArrayList;");
    if(pathsField == NULL)
    {
        return NULL;
    }

    peer_constructor = env->GetMethodID(peerClass, "<init>", "()V");
    if(peer_constructor == NULL)
    {
        return NULL;
    }

    jobject peerObject = env->NewObject(peerClass, peer_constructor);
    if(peerObject == NULL)
    {
        return NULL; // out of memory
    }

    env->SetLongField(peerClass, addressField, (jlong)peer.address);
    env->SetLongField(peerClass, lastUnicastFrameField, (jlong)peer.lastUnicastFrame);
    env->SetLongField(peerClass, lastMulticastFrameField, (jlong)peer.lastMulticastFrame);
    env->SetIntField(peerClass, versionMajorField, peer.versionMajor);
    env->SetIntField(peerClass, versionMinorField, peer.versionMinor);
    env->SetIntField(peerClass, versionRevField, peer.versionRev);
    env->SetIntField(peerClass, latencyField, peer.latency);
    env->SetObjectField(peerClass, roleField, createPeerRole(env, peer.role));

    jobject arrayObject = newArrayList(env);
    for(unsigned int i = 0; i < peer.pathCount; ++i)
    {
        jobject path = newPeerPhysicalPath(env, peer.paths[i]);
        appendItemToArrayList(env, arrayObject, path);
    }

    env->SetObjectField(peerClass, pathsField, arrayObject);

    return peerObject;
}

jobject newNetworkConfig(JNIEnv *env, const ZT1_VirtualNetworkConfig &vnetConfig)
{
    jclass vnetConfigClass = NULL;
    jmethodID vnetConfig_constructor = NULL;
    jfieldID nwidField = NULL;
    jfieldID macField = NULL;
    jfieldID nameField = NULL;
    jfieldID statusField = NULL;
    jfieldID typeField = NULL;
    jfieldID mtuField = NULL;
    jfieldID dhcpField = NULL;
    jfieldID bridgeField = NULL;
    jfieldID broadcastEnabledField = NULL;
    jfieldID portErrorField = NULL;
    jfieldID enabledField = NULL;
    jfieldID netconfRevisionField = NULL;
    jfieldID multicastSubscriptionsField = NULL;
    jfieldID assignedAddressesField = NULL;

    vnetConfigClass = env->FindClass("com/zerotierone/sdk/VirtualNetworkConfig");
    if(vnetConfigClass == NULL)
    {
        LOGE("Couldn't find com.zerotierone.sdk.VirtualNetworkConfig");
        return NULL;
    }

    vnetConfig_constructor = env->GetMethodID(
        vnetConfigClass, "<init>", "()V");
    if(vnetConfig_constructor == NULL)
    {
        LOGE("Couldn't find VirtualNetworkConfig Constructor");
        return NULL;
    }

    jobject vnetConfigObj = env->NewObject(vnetConfigClass, vnetConfig_constructor);
    if(vnetConfigObj == NULL)
    {
        LOGE("Error creating new VirtualNetworkConfig object");
        return NULL;
    }

    nwidField = env->GetFieldID(vnetConfigClass, "nwid", "J");
    if(nwidField == NULL)
    {
        LOGE("Error getting nwid field");
        return NULL;
    }

    macField = env->GetFieldID(vnetConfigClass, "mac", "J");
    if(macField == NULL)
    {
        LOGE("Error getting mac field");
        return NULL;
    }

    nameField = env->GetFieldID(vnetConfigClass, "name", "Ljava/lang/String;");
    if(nameField == NULL)
    {
        LOGE("Error getting name field");
        return NULL;
    }

    statusField = env->GetFieldID(vnetConfigClass, "status", "Lcom/zerotierone/sdk/VirtualNetworkStatus;");
    if(statusField == NULL)
    {
        LOGE("Error getting status field");
        return NULL;
    }

    typeField = env->GetFieldID(vnetConfigClass, "type", "Lcom/zerotierone/sdk/VirtualNetworkType;");
    if(typeField == NULL)
    {
        LOGE("Error getting type field");
        return NULL;
    }

    mtuField = env->GetFieldID(vnetConfigClass, "mtu", "I");
    if(mtuField == NULL)
    {
        LOGE("Error getting mtu field");
        return NULL;
    }

    dhcpField = env->GetFieldID(vnetConfigClass, "dhcp", "Z");
    if(dhcpField == NULL)
    {
        LOGE("Error getting dhcp field");
        return NULL;
    }

    bridgeField = env->GetFieldID(vnetConfigClass, "bridge", "Z");
    if(bridgeField == NULL)
    {
        LOGE("Error getting bridge field");
        return NULL;
    }

    broadcastEnabledField = env->GetFieldID(vnetConfigClass, "broadcastEnabled", "Z");
    if(broadcastEnabledField == NULL)
    {
        LOGE("Error getting broadcastEnabled field");
        return NULL;
    }

    portErrorField = env->GetFieldID(vnetConfigClass, "portError", "I");
    if(portErrorField == NULL)
    {
        LOGE("Error getting portError field");
        return NULL;
    }

    enabledField = env->GetFieldID(vnetConfigClass, "enabled", "Z");
    if(enabledField == NULL)
    {
        LOGE("Error getting enabled field");
        return NULL;
    }

    netconfRevisionField = env->GetFieldID(vnetConfigClass, "netconfRevision", "J");
    if(netconfRevisionField == NULL)
    {
        LOGE("Error getting netconfRevision field");
        return NULL;
    }

    multicastSubscriptionsField = env->GetFieldID(vnetConfigClass, "multicastSubscriptions", "Ljava/util/ArrayList;");
    if(multicastSubscriptionsField == NULL)
    {
        LOGE("Error getting multicastSubscriptions field");
        return NULL;
    }

    assignedAddressesField = env->GetFieldID(vnetConfigClass, "assignedAddresses", "Ljava/util/ArrayList;");
    if(assignedAddressesField == NULL)
    {
        LOGE("Error getting assignedAddresses field");
        return NULL;
    }

    env->SetLongField(vnetConfigObj, nwidField, vnetConfig.nwid);
    env->SetLongField(vnetConfigObj, macField, vnetConfig.mac);
    jstring nameStr = env->NewStringUTF(vnetConfig.name);
    if(nameStr == NULL)
    {
        return NULL; // out of memory
    }
    env->SetObjectField(vnetConfigObj, nameField, nameStr);

    jobject statusObject = createVirtualNetworkStatus(env, vnetConfig.status);
    if(statusObject == NULL)
    {
        return NULL;
    }
    env->SetObjectField(vnetConfigObj, statusField, statusObject);

    jobject typeObject = createVirtualNetworkType(env, vnetConfig.type);
    if(typeObject == NULL)
    {
        return NULL;
    }
    env->SetObjectField(vnetConfigObj, typeField, typeObject);

    env->SetIntField(vnetConfigObj, mtuField, vnetConfig.mtu);
    env->SetBooleanField(vnetConfigObj, dhcpField, vnetConfig.dhcp);
    env->SetBooleanField(vnetConfigObj, bridgeField, vnetConfig.bridge);
    env->SetBooleanField(vnetConfigObj, broadcastEnabledField, vnetConfig.broadcastEnabled);
    env->SetIntField(vnetConfigObj, portErrorField, vnetConfig.portError);


    jobject mcastSubsArrayObj = newArrayList(env);
    for(unsigned int i = 0; i < vnetConfig.multicastSubscriptionCount; ++i)
    {
        jobject mcastObj = newMulticastGroup(env, vnetConfig.multicastSubscriptions[i]);
        appendItemToArrayList(env, mcastSubsArrayObj, mcastObj);
    }
    env->SetObjectField(vnetConfigObj, multicastSubscriptionsField, mcastSubsArrayObj);


    jobject assignedAddrArrayObj = newArrayList(env);
    for(unsigned int i = 0; i < vnetConfig.assignedAddressCount; ++i)
    {
        jobject inetAddrObj = newInetAddress(env, vnetConfig.assignedAddresses[i]);
        appendItemToArrayList(env, assignedAddrArrayObj, inetAddrObj);
    }

    env->SetObjectField(vnetConfigObj, assignedAddressesField, assignedAddrArrayObj);

    return vnetConfigObj;
}

jobject newVersion(JNIEnv *env, int major, int minor, int rev, long featureFlags)
{
   // create a com.zerotierone.sdk.Version object
    jclass versionClass = NULL;
    jmethodID versionConstructor = NULL;

    versionClass = env->FindClass("com/zerotierone/sdk/Version");
    if(versionClass == NULL)
    {
        return NULL;
    }

    versionConstructor = env->GetMethodID(
        versionClass, "<init>", "()V");
    if(versionConstructor == NULL)
    {
        return NULL;
    }

    jobject versionObj = env->NewObject(versionClass, versionConstructor);
    if(versionObj == NULL)
    {
        return NULL;
    }

    // copy data to Version object
    jfieldID majorField = NULL;
    jfieldID minorField = NULL;
    jfieldID revisionField = NULL;
    jfieldID featureFlagsField = NULL;

    majorField = env->GetFieldID(versionClass, "major", "I");
    if(majorField == NULL)
    {
        return NULL;
    }

    minorField = env->GetFieldID(versionClass, "minor", "I");
    if(minorField == NULL)
    {
        return NULL;
    }

    revisionField = env->GetFieldID(versionClass, "revision", "I");
    if(revisionField == NULL)
    {
        return NULL;
    }

    featureFlagsField = env->GetFieldID(versionClass, "featureFlags", "J");
    if(featureFlagsField == NULL)
    {
        return NULL;
    }

    env->SetIntField(versionObj, majorField, (jint)major);
    env->SetIntField(versionObj, minorField, (jint)minor);
    env->SetIntField(versionObj, revisionField, (jint)rev);
    env->SetLongField(versionObj, featureFlagsField, (jlong)featureFlags); 

    return versionObj;
}

#ifdef __cplusplus
}
#endif