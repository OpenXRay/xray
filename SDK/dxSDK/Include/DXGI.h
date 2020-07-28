

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for dxgi.idl:
    Oicf, W1, Zp8, env=Win64 (32b run)
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __dxgi_h__
#define __dxgi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDXGIObject_FWD_DEFINED__
#define __IDXGIObject_FWD_DEFINED__
typedef interface IDXGIObject IDXGIObject;
#endif 	/* __IDXGIObject_FWD_DEFINED__ */


#ifndef __IDXGIDeviceSubObject_FWD_DEFINED__
#define __IDXGIDeviceSubObject_FWD_DEFINED__
typedef interface IDXGIDeviceSubObject IDXGIDeviceSubObject;
#endif 	/* __IDXGIDeviceSubObject_FWD_DEFINED__ */


#ifndef __IDXGIResource_FWD_DEFINED__
#define __IDXGIResource_FWD_DEFINED__
typedef interface IDXGIResource IDXGIResource;
#endif 	/* __IDXGIResource_FWD_DEFINED__ */


#ifndef __IDXGISurface_FWD_DEFINED__
#define __IDXGISurface_FWD_DEFINED__
typedef interface IDXGISurface IDXGISurface;
#endif 	/* __IDXGISurface_FWD_DEFINED__ */


#ifndef __IDXGIAdapter_FWD_DEFINED__
#define __IDXGIAdapter_FWD_DEFINED__
typedef interface IDXGIAdapter IDXGIAdapter;
#endif 	/* __IDXGIAdapter_FWD_DEFINED__ */


#ifndef __IDXGIOutput_FWD_DEFINED__
#define __IDXGIOutput_FWD_DEFINED__
typedef interface IDXGIOutput IDXGIOutput;
#endif 	/* __IDXGIOutput_FWD_DEFINED__ */


#ifndef __IDXGISwapChain_FWD_DEFINED__
#define __IDXGISwapChain_FWD_DEFINED__
typedef interface IDXGISwapChain IDXGISwapChain;
#endif 	/* __IDXGISwapChain_FWD_DEFINED__ */


#ifndef __IDXGIFactory_FWD_DEFINED__
#define __IDXGIFactory_FWD_DEFINED__
typedef interface IDXGIFactory IDXGIFactory;
#endif 	/* __IDXGIFactory_FWD_DEFINED__ */


#ifndef __IDXGIDevice_FWD_DEFINED__
#define __IDXGIDevice_FWD_DEFINED__
typedef interface IDXGIDevice IDXGIDevice;
#endif 	/* __IDXGIDevice_FWD_DEFINED__ */


/* header files for imported files */
#include "dxgitype.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dxgi_0000_0000 */
/* [local] */ 

#define DXGI_CPU_ACCESS_NONE    ( 0 )
#define DXGI_CPU_ACCESS_DYNAMIC    ( 1 )
#define DXGI_CPU_ACCESS_READ_WRITE    ( 2 )
#define DXGI_CPU_ACCESS_SCRATCH    ( 3 )
#define DXGI_CPU_ACCESS_FIELD        15
#define DXGI_USAGE_SHADER_INPUT             ( 1L << (0 + 4) )
#define DXGI_USAGE_RENDER_TARGET_OUTPUT     ( 1L << (1 + 4) )
#define DXGI_USAGE_BACK_BUFFER              ( 1L << (2 + 4) )
#define DXGI_USAGE_SHARED                   ( 1L << (3 + 4) )
#define DXGI_USAGE_READ_ONLY                ( 1L << (4 + 4) )
#define DXGI_USAGE_DISCARD_ON_PRESENT       ( 1L << (5 + 4) )
typedef UINT DXGI_USAGE;

typedef struct DXGI_FRAME_STATISTICS
    {
    UINT PresentCount;
    UINT PresentRefreshCount;
    UINT SyncRefreshCount;
    LARGE_INTEGER SyncQPCTime;
    LARGE_INTEGER SyncGPUTime;
    } 	DXGI_FRAME_STATISTICS;

typedef struct DXGI_MAPPED_RECT
    {
    INT Pitch;
    BYTE *pBits;
    } 	DXGI_MAPPED_RECT;

#ifdef __midl
typedef struct _LUID
    {
    DWORD LowPart;
    LONG HighPart;
    } 	LUID;

typedef struct _LUID *PLUID;

#endif
typedef struct DXGI_ADAPTER_DESC
    {
    WCHAR Description[ 128 ];
    UINT VendorId;
    UINT DeviceId;
    UINT SubSysId;
    UINT Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID AdapterLuid;
    } 	DXGI_ADAPTER_DESC;

#if !defined(HMONITOR_DECLARED) && !defined(HMONITOR) && (WINVER < 0x0500)
#define HMONITOR_DECLARED
#if 0
typedef HANDLE HMONITOR;

#endif
DECLARE_HANDLE(HMONITOR);
#endif
typedef struct DXGI_OUTPUT_DESC
    {
    WCHAR DeviceName[ 32 ];
    RECT DesktopCoordinates;
    BOOL AttachedToDesktop;
    DXGI_MODE_ROTATION Rotation;
    HMONITOR Monitor;
    } 	DXGI_OUTPUT_DESC;

typedef struct DXGI_SHARED_RESOURCE
    {
    HANDLE Handle;
    } 	DXGI_SHARED_RESOURCE;

#define	DXGI_RESOURCE_PRIORITY_MINIMUM	( 0x28000000 )

#define	DXGI_RESOURCE_PRIORITY_LOW	( 0x50000000 )

#define	DXGI_RESOURCE_PRIORITY_NORMAL	( 0x78000000 )

#define	DXGI_RESOURCE_PRIORITY_HIGH	( 0xa0000000 )

#define	DXGI_RESOURCE_PRIORITY_MAXIMUM	( 0xc8000000 )

typedef 
enum DXGI_RESIDENCY
    {	DXGI_RESIDENCY_FULLY_RESIDENT	= 1,
	DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY	= 2,
	DXGI_RESIDENCY_EVICTED_TO_DISK	= 3
    } 	DXGI_RESIDENCY;

typedef struct DXGI_SURFACE_DESC
    {
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    DXGI_SAMPLE_DESC SampleDesc;
    } 	DXGI_SURFACE_DESC;

typedef 
enum DXGI_SWAP_EFFECT
    {	DXGI_SWAP_EFFECT_DISCARD	= 0,
	DXGI_SWAP_EFFECT_SEQUENTIAL	= 1
    } 	DXGI_SWAP_EFFECT;

typedef 
enum DXGI_SWAP_CHAIN_FLAG
    {	DXGI_SWAP_CHAIN_FLAG_NONPREROTATED	= 1,
	DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH	= 2
    } 	DXGI_SWAP_CHAIN_FLAG;

typedef struct DXGI_SWAP_CHAIN_DESC
    {
    DXGI_MODE_DESC BufferDesc;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE BufferUsage;
    UINT BufferCount;
    HWND OutputWindow;
    BOOL Windowed;
    DXGI_SWAP_EFFECT SwapEffect;
    UINT Flags;
    } 	DXGI_SWAP_CHAIN_DESC;



extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0000_v0_0_s_ifspec;

#ifndef __IDXGIObject_INTERFACE_DEFINED__
#define __IDXGIObject_INTERFACE_DEFINED__

/* interface IDXGIObject */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("aec22fb8-76f3-4639-9be0-28eb43a67a2e")
    IDXGIObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPrivateData( 
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface( 
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateData( 
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParent( 
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIObject * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIObject * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIObject * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIObject * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        END_INTERFACE
    } IDXGIObjectVtbl;

    interface IDXGIObject
    {
        CONST_VTBL struct IDXGIObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIObject_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIObject_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIObject_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIObject_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIObject_INTERFACE_DEFINED__ */


#ifndef __IDXGIDeviceSubObject_INTERFACE_DEFINED__
#define __IDXGIDeviceSubObject_INTERFACE_DEFINED__

/* interface IDXGIDeviceSubObject */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIDeviceSubObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3d3e0379-f9de-4d58-bb6c-18d62992f1a6")
    IDXGIDeviceSubObject : public IDXGIObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppDevice) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIDeviceSubObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIDeviceSubObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIDeviceSubObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDXGIDeviceSubObject * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppDevice);
        
        END_INTERFACE
    } IDXGIDeviceSubObjectVtbl;

    interface IDXGIDeviceSubObject
    {
        CONST_VTBL struct IDXGIDeviceSubObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIDeviceSubObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIDeviceSubObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIDeviceSubObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIDeviceSubObject_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIDeviceSubObject_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIDeviceSubObject_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIDeviceSubObject_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIDeviceSubObject_GetDevice(This,riid,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,riid,ppDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIDeviceSubObject_INTERFACE_DEFINED__ */


#ifndef __IDXGIResource_INTERFACE_DEFINED__
#define __IDXGIResource_INTERFACE_DEFINED__

/* interface IDXGIResource */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("035f3ab4-482e-4e50-b41f-8a7f8bd8960b")
    IDXGIResource : public IDXGIDeviceSubObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSharedHandle( 
            /* [out] */ HANDLE *pSharedHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsage( 
            /* [out] */ DXGI_USAGE *pUsage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEvictionPriority( 
            /* [in] */ UINT EvictionPriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEvictionPriority( 
            /* [retval][out] */ UINT *pEvictionPriority) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIResource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIResource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIResource * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIResource * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIResource * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIResource * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDXGIResource * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetSharedHandle )( 
            IDXGIResource * This,
            /* [out] */ HANDLE *pSharedHandle);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsage )( 
            IDXGIResource * This,
            /* [out] */ DXGI_USAGE *pUsage);
        
        HRESULT ( STDMETHODCALLTYPE *SetEvictionPriority )( 
            IDXGIResource * This,
            /* [in] */ UINT EvictionPriority);
        
        HRESULT ( STDMETHODCALLTYPE *GetEvictionPriority )( 
            IDXGIResource * This,
            /* [retval][out] */ UINT *pEvictionPriority);
        
        END_INTERFACE
    } IDXGIResourceVtbl;

    interface IDXGIResource
    {
        CONST_VTBL struct IDXGIResourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIResource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIResource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIResource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIResource_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIResource_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIResource_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIResource_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIResource_GetDevice(This,riid,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,riid,ppDevice) ) 


#define IDXGIResource_GetSharedHandle(This,pSharedHandle)	\
    ( (This)->lpVtbl -> GetSharedHandle(This,pSharedHandle) ) 

#define IDXGIResource_GetUsage(This,pUsage)	\
    ( (This)->lpVtbl -> GetUsage(This,pUsage) ) 

#define IDXGIResource_SetEvictionPriority(This,EvictionPriority)	\
    ( (This)->lpVtbl -> SetEvictionPriority(This,EvictionPriority) ) 

#define IDXGIResource_GetEvictionPriority(This,pEvictionPriority)	\
    ( (This)->lpVtbl -> GetEvictionPriority(This,pEvictionPriority) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIResource_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0003 */
/* [local] */ 

#define	DXGI_MAP_READ	( 1UL )

#define	DXGI_MAP_WRITE	( 2UL )

#define	DXGI_MAP_DISCARD	( 4UL )



extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0003_v0_0_s_ifspec;

#ifndef __IDXGISurface_INTERFACE_DEFINED__
#define __IDXGISurface_INTERFACE_DEFINED__

/* interface IDXGISurface */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGISurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cafcb56c-6ac3-4889-bf47-9e23bbd260ec")
    IDXGISurface : public IDXGIDeviceSubObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDesc( 
            /* [out] */ DXGI_SURFACE_DESC *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Map( 
            /* [out] */ DXGI_MAPPED_RECT *pLockedRect,
            /* [in] */ UINT MapFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unmap( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGISurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGISurface * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGISurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGISurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGISurface * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGISurface * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGISurface * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGISurface * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDXGISurface * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGISurface * This,
            /* [out] */ DXGI_SURFACE_DESC *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *Map )( 
            IDXGISurface * This,
            /* [out] */ DXGI_MAPPED_RECT *pLockedRect,
            /* [in] */ UINT MapFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Unmap )( 
            IDXGISurface * This);
        
        END_INTERFACE
    } IDXGISurfaceVtbl;

    interface IDXGISurface
    {
        CONST_VTBL struct IDXGISurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGISurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGISurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGISurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGISurface_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGISurface_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGISurface_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGISurface_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGISurface_GetDevice(This,riid,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,riid,ppDevice) ) 


#define IDXGISurface_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGISurface_Map(This,pLockedRect,MapFlags)	\
    ( (This)->lpVtbl -> Map(This,pLockedRect,MapFlags) ) 

#define IDXGISurface_Unmap(This)	\
    ( (This)->lpVtbl -> Unmap(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGISurface_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0004 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0004_v0_0_s_ifspec;

#ifndef __IDXGIAdapter_INTERFACE_DEFINED__
#define __IDXGIAdapter_INTERFACE_DEFINED__

/* interface IDXGIAdapter */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2411e7e1-12ac-4ccf-bd14-9798e8534dc0")
    IDXGIAdapter : public IDXGIObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumOutputs( 
            /* [in] */ UINT Output,
            /* [out][in] */ IDXGIOutput **ppOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDesc( 
            /* [out] */ DXGI_ADAPTER_DESC *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckInterfaceSupport( 
            /* [in] */ REFGUID InterfaceName,
            /* [out] */ LARGE_INTEGER *pUMDVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIAdapterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIAdapter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIAdapter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIAdapter * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIAdapter * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIAdapter * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIAdapter * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIAdapter * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *EnumOutputs )( 
            IDXGIAdapter * This,
            /* [in] */ UINT Output,
            /* [out][in] */ IDXGIOutput **ppOutput);
        
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGIAdapter * This,
            /* [out] */ DXGI_ADAPTER_DESC *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *CheckInterfaceSupport )( 
            IDXGIAdapter * This,
            /* [in] */ REFGUID InterfaceName,
            /* [out] */ LARGE_INTEGER *pUMDVersion);
        
        END_INTERFACE
    } IDXGIAdapterVtbl;

    interface IDXGIAdapter
    {
        CONST_VTBL struct IDXGIAdapterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIAdapter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIAdapter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIAdapter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIAdapter_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIAdapter_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIAdapter_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIAdapter_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIAdapter_EnumOutputs(This,Output,ppOutput)	\
    ( (This)->lpVtbl -> EnumOutputs(This,Output,ppOutput) ) 

#define IDXGIAdapter_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGIAdapter_CheckInterfaceSupport(This,InterfaceName,pUMDVersion)	\
    ( (This)->lpVtbl -> CheckInterfaceSupport(This,InterfaceName,pUMDVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIAdapter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0005 */
/* [local] */ 

#define	DXGI_ENUM_MODES_INTERLACED	( 1UL )

#define	DXGI_ENUM_MODES_SCALING	( 2UL )



extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0005_v0_0_s_ifspec;

#ifndef __IDXGIOutput_INTERFACE_DEFINED__
#define __IDXGIOutput_INTERFACE_DEFINED__

/* interface IDXGIOutput */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ae02eedb-c735-4690-8d52-5a8dc20213aa")
    IDXGIOutput : public IDXGIObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDesc( 
            /* [out] */ DXGI_OUTPUT_DESC *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayModeList( 
            /* [in] */ DXGI_FORMAT EnumFormat,
            /* [in] */ UINT Flags,
            /* [out][in] */ UINT *pNumModes,
            /* [out] */ DXGI_MODE_DESC *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindClosestMatchingMode( 
            /* [in] */ const DXGI_MODE_DESC *pModeToMatch,
            /* [out] */ DXGI_MODE_DESC *pClosestMatch,
            /* [in] */ IUnknown *pConcernedDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForVBlank( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TakeOwnership( 
            /* [in] */ IUnknown *pDevice,
            BOOL Exclusive) = 0;
        
        virtual void STDMETHODCALLTYPE ReleaseOwnership( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGammaControlCapabilities( 
            /* [out] */ DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGammaControl( 
            /* [in] */ const DXGI_GAMMA_CONTROL *pArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGammaControl( 
            /* [out] */ DXGI_GAMMA_CONTROL *pArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDisplaySurface( 
            /* [in] */ IDXGISurface *pScanoutSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplaySurfaceData( 
            /* [in] */ IDXGISurface *pDestination) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics( 
            /* [out] */ DXGI_FRAME_STATISTICS *pStats) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIOutput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIOutput * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIOutput * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIOutput * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIOutput * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGIOutput * This,
            /* [out] */ DXGI_OUTPUT_DESC *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayModeList )( 
            IDXGIOutput * This,
            /* [in] */ DXGI_FORMAT EnumFormat,
            /* [in] */ UINT Flags,
            /* [out][in] */ UINT *pNumModes,
            /* [out] */ DXGI_MODE_DESC *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *FindClosestMatchingMode )( 
            IDXGIOutput * This,
            /* [in] */ const DXGI_MODE_DESC *pModeToMatch,
            /* [out] */ DXGI_MODE_DESC *pClosestMatch,
            /* [in] */ IUnknown *pConcernedDevice);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForVBlank )( 
            IDXGIOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *TakeOwnership )( 
            IDXGIOutput * This,
            /* [in] */ IUnknown *pDevice,
            BOOL Exclusive);
        
        void ( STDMETHODCALLTYPE *ReleaseOwnership )( 
            IDXGIOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGammaControlCapabilities )( 
            IDXGIOutput * This,
            /* [out] */ DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCaps);
        
        HRESULT ( STDMETHODCALLTYPE *SetGammaControl )( 
            IDXGIOutput * This,
            /* [in] */ const DXGI_GAMMA_CONTROL *pArray);
        
        HRESULT ( STDMETHODCALLTYPE *GetGammaControl )( 
            IDXGIOutput * This,
            /* [out] */ DXGI_GAMMA_CONTROL *pArray);
        
        HRESULT ( STDMETHODCALLTYPE *SetDisplaySurface )( 
            IDXGIOutput * This,
            /* [in] */ IDXGISurface *pScanoutSurface);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplaySurfaceData )( 
            IDXGIOutput * This,
            /* [in] */ IDXGISurface *pDestination);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameStatistics )( 
            IDXGIOutput * This,
            /* [out] */ DXGI_FRAME_STATISTICS *pStats);
        
        END_INTERFACE
    } IDXGIOutputVtbl;

    interface IDXGIOutput
    {
        CONST_VTBL struct IDXGIOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIOutput_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIOutput_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIOutput_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIOutput_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIOutput_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGIOutput_GetDisplayModeList(This,EnumFormat,Flags,pNumModes,pDesc)	\
    ( (This)->lpVtbl -> GetDisplayModeList(This,EnumFormat,Flags,pNumModes,pDesc) ) 

#define IDXGIOutput_FindClosestMatchingMode(This,pModeToMatch,pClosestMatch,pConcernedDevice)	\
    ( (This)->lpVtbl -> FindClosestMatchingMode(This,pModeToMatch,pClosestMatch,pConcernedDevice) ) 

#define IDXGIOutput_WaitForVBlank(This)	\
    ( (This)->lpVtbl -> WaitForVBlank(This) ) 

#define IDXGIOutput_TakeOwnership(This,pDevice,Exclusive)	\
    ( (This)->lpVtbl -> TakeOwnership(This,pDevice,Exclusive) ) 

#define IDXGIOutput_ReleaseOwnership(This)	\
    ( (This)->lpVtbl -> ReleaseOwnership(This) ) 

#define IDXGIOutput_GetGammaControlCapabilities(This,pGammaCaps)	\
    ( (This)->lpVtbl -> GetGammaControlCapabilities(This,pGammaCaps) ) 

#define IDXGIOutput_SetGammaControl(This,pArray)	\
    ( (This)->lpVtbl -> SetGammaControl(This,pArray) ) 

#define IDXGIOutput_GetGammaControl(This,pArray)	\
    ( (This)->lpVtbl -> GetGammaControl(This,pArray) ) 

#define IDXGIOutput_SetDisplaySurface(This,pScanoutSurface)	\
    ( (This)->lpVtbl -> SetDisplaySurface(This,pScanoutSurface) ) 

#define IDXGIOutput_GetDisplaySurfaceData(This,pDestination)	\
    ( (This)->lpVtbl -> GetDisplaySurfaceData(This,pDestination) ) 

#define IDXGIOutput_GetFrameStatistics(This,pStats)	\
    ( (This)->lpVtbl -> GetFrameStatistics(This,pStats) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIOutput_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0006 */
/* [local] */ 

#define DXGI_MAX_SWAP_CHAIN_BUFFERS        ( 16 )
#define DXGI_PRESENT_TEST               0x00000001UL
#define DXGI_PRESENT_DO_NOT_SEQUENCE    0x00000002UL
#define DXGI_PRESENT_RESTART            0x00000004UL


extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0006_v0_0_s_ifspec;

#ifndef __IDXGISwapChain_INTERFACE_DEFINED__
#define __IDXGISwapChain_INTERFACE_DEFINED__

/* interface IDXGISwapChain */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGISwapChain;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("310d36a0-d2e7-4c0a-aa04-6a9d23b8886a")
    IDXGISwapChain : public IDXGIDeviceSubObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Present( 
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [in] */ UINT Buffer,
            /* [in] */ REFIID riid,
            /* [out][in] */ void **ppSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFullscreenState( 
            /* [in] */ BOOL Fullscreen,
            /* [in] */ IDXGIOutput *pTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFullscreenState( 
            /* [out] */ BOOL *pFullscreen,
            /* [out] */ IDXGIOutput **ppTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDesc( 
            /* [out] */ DXGI_SWAP_CHAIN_DESC *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResizeBuffers( 
            /* [in] */ UINT BufferCount,
            /* [in] */ UINT Width,
            /* [in] */ UINT Height,
            /* [in] */ DXGI_FORMAT NewFormat,
            /* [in] */ UINT SwapChainFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResizeTarget( 
            /* [in] */ const DXGI_MODE_DESC *pNewTargetParameters) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainingOutput( 
            IDXGIOutput **ppOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics( 
            /* [out] */ DXGI_FRAME_STATISTICS *pStats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount( 
            /* [out] */ UINT *pLastPresentCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGISwapChainVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGISwapChain * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGISwapChain * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGISwapChain * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGISwapChain * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGISwapChain * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGISwapChain * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGISwapChain * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDXGISwapChain * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppDevice);
        
        HRESULT ( STDMETHODCALLTYPE *Present )( 
            IDXGISwapChain * This,
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT Flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IDXGISwapChain * This,
            /* [in] */ UINT Buffer,
            /* [in] */ REFIID riid,
            /* [out][in] */ void **ppSurface);
        
        HRESULT ( STDMETHODCALLTYPE *SetFullscreenState )( 
            IDXGISwapChain * This,
            /* [in] */ BOOL Fullscreen,
            /* [in] */ IDXGIOutput *pTarget);
        
        HRESULT ( STDMETHODCALLTYPE *GetFullscreenState )( 
            IDXGISwapChain * This,
            /* [out] */ BOOL *pFullscreen,
            /* [out] */ IDXGIOutput **ppTarget);
        
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGISwapChain * This,
            /* [out] */ DXGI_SWAP_CHAIN_DESC *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *ResizeBuffers )( 
            IDXGISwapChain * This,
            /* [in] */ UINT BufferCount,
            /* [in] */ UINT Width,
            /* [in] */ UINT Height,
            /* [in] */ DXGI_FORMAT NewFormat,
            /* [in] */ UINT SwapChainFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ResizeTarget )( 
            IDXGISwapChain * This,
            /* [in] */ const DXGI_MODE_DESC *pNewTargetParameters);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainingOutput )( 
            IDXGISwapChain * This,
            IDXGIOutput **ppOutput);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameStatistics )( 
            IDXGISwapChain * This,
            /* [out] */ DXGI_FRAME_STATISTICS *pStats);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastPresentCount )( 
            IDXGISwapChain * This,
            /* [out] */ UINT *pLastPresentCount);
        
        END_INTERFACE
    } IDXGISwapChainVtbl;

    interface IDXGISwapChain
    {
        CONST_VTBL struct IDXGISwapChainVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGISwapChain_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGISwapChain_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGISwapChain_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGISwapChain_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGISwapChain_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGISwapChain_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGISwapChain_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGISwapChain_GetDevice(This,riid,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,riid,ppDevice) ) 


#define IDXGISwapChain_Present(This,SyncInterval,Flags)	\
    ( (This)->lpVtbl -> Present(This,SyncInterval,Flags) ) 

#define IDXGISwapChain_GetBuffer(This,Buffer,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetBuffer(This,Buffer,riid,ppSurface) ) 

#define IDXGISwapChain_SetFullscreenState(This,Fullscreen,pTarget)	\
    ( (This)->lpVtbl -> SetFullscreenState(This,Fullscreen,pTarget) ) 

#define IDXGISwapChain_GetFullscreenState(This,pFullscreen,ppTarget)	\
    ( (This)->lpVtbl -> GetFullscreenState(This,pFullscreen,ppTarget) ) 

#define IDXGISwapChain_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGISwapChain_ResizeBuffers(This,BufferCount,Width,Height,NewFormat,SwapChainFlags)	\
    ( (This)->lpVtbl -> ResizeBuffers(This,BufferCount,Width,Height,NewFormat,SwapChainFlags) ) 

#define IDXGISwapChain_ResizeTarget(This,pNewTargetParameters)	\
    ( (This)->lpVtbl -> ResizeTarget(This,pNewTargetParameters) ) 

#define IDXGISwapChain_GetContainingOutput(This,ppOutput)	\
    ( (This)->lpVtbl -> GetContainingOutput(This,ppOutput) ) 

#define IDXGISwapChain_GetFrameStatistics(This,pStats)	\
    ( (This)->lpVtbl -> GetFrameStatistics(This,pStats) ) 

#define IDXGISwapChain_GetLastPresentCount(This,pLastPresentCount)	\
    ( (This)->lpVtbl -> GetLastPresentCount(This,pLastPresentCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGISwapChain_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0007 */
/* [local] */ 

#define DXGI_MWA_NO_WINDOW_CHANGES      ( 1 << 0 )
#define DXGI_MWA_NO_ALT_ENTER           ( 1 << 1 )
#define DXGI_MWA_NO_PRINT_SCREEN        ( 1 << 2 )
#define DXGI_MWA_VALID                  ( 0x7 )


extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0007_v0_0_s_ifspec;

#ifndef __IDXGIFactory_INTERFACE_DEFINED__
#define __IDXGIFactory_INTERFACE_DEFINED__

/* interface IDXGIFactory */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7b7166ec-21c7-44ae-b21a-c9ae321ae369")
    IDXGIFactory : public IDXGIObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumAdapters( 
            /* [in] */ UINT Adapter,
            /* [out] */ IDXGIAdapter **ppAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation( 
            HWND WindowHandle,
            UINT Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation( 
            HWND *pWindowHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSwapChain( 
            IUnknown *pDevice,
            DXGI_SWAP_CHAIN_DESC *pDesc,
            IDXGISwapChain **ppSwapChain) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter( 
            /* [in] */ HMODULE Module,
            /* [out] */ IDXGIAdapter **ppAdapter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIFactory * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIFactory * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIFactory * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIFactory * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *EnumAdapters )( 
            IDXGIFactory * This,
            /* [in] */ UINT Adapter,
            /* [out] */ IDXGIAdapter **ppAdapter);
        
        HRESULT ( STDMETHODCALLTYPE *MakeWindowAssociation )( 
            IDXGIFactory * This,
            HWND WindowHandle,
            UINT Flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindowAssociation )( 
            IDXGIFactory * This,
            HWND *pWindowHandle);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChain )( 
            IDXGIFactory * This,
            IUnknown *pDevice,
            DXGI_SWAP_CHAIN_DESC *pDesc,
            IDXGISwapChain **ppSwapChain);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSoftwareAdapter )( 
            IDXGIFactory * This,
            /* [in] */ HMODULE Module,
            /* [out] */ IDXGIAdapter **ppAdapter);
        
        END_INTERFACE
    } IDXGIFactoryVtbl;

    interface IDXGIFactory
    {
        CONST_VTBL struct IDXGIFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIFactory_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIFactory_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIFactory_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIFactory_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIFactory_EnumAdapters(This,Adapter,ppAdapter)	\
    ( (This)->lpVtbl -> EnumAdapters(This,Adapter,ppAdapter) ) 

#define IDXGIFactory_MakeWindowAssociation(This,WindowHandle,Flags)	\
    ( (This)->lpVtbl -> MakeWindowAssociation(This,WindowHandle,Flags) ) 

#define IDXGIFactory_GetWindowAssociation(This,pWindowHandle)	\
    ( (This)->lpVtbl -> GetWindowAssociation(This,pWindowHandle) ) 

#define IDXGIFactory_CreateSwapChain(This,pDevice,pDesc,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChain(This,pDevice,pDesc,ppSwapChain) ) 

#define IDXGIFactory_CreateSoftwareAdapter(This,Module,ppAdapter)	\
    ( (This)->lpVtbl -> CreateSoftwareAdapter(This,Module,ppAdapter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0008 */
/* [local] */ 

HRESULT WINAPI CreateDXGIFactory(REFIID riid, void **ppFactory);


extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0008_v0_0_s_ifspec;

#ifndef __IDXGIDevice_INTERFACE_DEFINED__
#define __IDXGIDevice_INTERFACE_DEFINED__

/* interface IDXGIDevice */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54ec77fa-1377-44e6-8c32-88fd5f44c84c")
    IDXGIDevice : public IDXGIObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAdapter( 
            /* [out] */ IDXGIAdapter **pAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSurface( 
            /* [in] */ const DXGI_SURFACE_DESC *pDesc,
            /* [in] */ UINT NumSurfaces,
            /* [in] */ DXGI_USAGE Usage,
            /* [in] */ const DXGI_SHARED_RESOURCE *pSharedResource,
            /* [out] */ IDXGISurface **ppSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryResourceResidency( 
            /* [size_is][in] */ IUnknown *const *ppResources,
            /* [size_is][out] */ DXGI_RESIDENCY *pResidencyStatus,
            /* [in] */ UINT NumResources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGPUThreadPriority( 
            /* [in] */ INT Priority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGPUThreadPriority( 
            /* [retval][out] */ INT *pPriority) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGIDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIDevice * This,
            /* [in] */ REFGUID Name,
            /* [in] */ UINT DataSize,
            /* [in] */ const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIDevice * This,
            /* [in] */ REFGUID Name,
            /* [in] */ const IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIDevice * This,
            /* [in] */ REFGUID Name,
            /* [out][in] */ UINT *pDataSize,
            /* [out] */ void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIDevice * This,
            /* [in] */ REFIID riid,
            /* [retval][out] */ void **ppParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdapter )( 
            IDXGIDevice * This,
            /* [out] */ IDXGIAdapter **pAdapter);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSurface )( 
            IDXGIDevice * This,
            /* [in] */ const DXGI_SURFACE_DESC *pDesc,
            /* [in] */ UINT NumSurfaces,
            /* [in] */ DXGI_USAGE Usage,
            /* [in] */ const DXGI_SHARED_RESOURCE *pSharedResource,
            /* [out] */ IDXGISurface **ppSurface);
        
        HRESULT ( STDMETHODCALLTYPE *QueryResourceResidency )( 
            IDXGIDevice * This,
            /* [size_is][in] */ IUnknown *const *ppResources,
            /* [size_is][out] */ DXGI_RESIDENCY *pResidencyStatus,
            /* [in] */ UINT NumResources);
        
        HRESULT ( STDMETHODCALLTYPE *SetGPUThreadPriority )( 
            IDXGIDevice * This,
            /* [in] */ INT Priority);
        
        HRESULT ( STDMETHODCALLTYPE *GetGPUThreadPriority )( 
            IDXGIDevice * This,
            /* [retval][out] */ INT *pPriority);
        
        END_INTERFACE
    } IDXGIDeviceVtbl;

    interface IDXGIDevice
    {
        CONST_VTBL struct IDXGIDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIDevice_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIDevice_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIDevice_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIDevice_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIDevice_GetAdapter(This,pAdapter)	\
    ( (This)->lpVtbl -> GetAdapter(This,pAdapter) ) 

#define IDXGIDevice_CreateSurface(This,pDesc,NumSurfaces,Usage,pSharedResource,ppSurface)	\
    ( (This)->lpVtbl -> CreateSurface(This,pDesc,NumSurfaces,Usage,pSharedResource,ppSurface) ) 

#define IDXGIDevice_QueryResourceResidency(This,ppResources,pResidencyStatus,NumResources)	\
    ( (This)->lpVtbl -> QueryResourceResidency(This,ppResources,pResidencyStatus,NumResources) ) 

#define IDXGIDevice_SetGPUThreadPriority(This,Priority)	\
    ( (This)->lpVtbl -> SetGPUThreadPriority(This,Priority) ) 

#define IDXGIDevice_GetGPUThreadPriority(This,pPriority)	\
    ( (This)->lpVtbl -> GetGPUThreadPriority(This,pPriority) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIDevice_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi_0000_0009 */
/* [local] */ 

#ifdef __cplusplus
#endif /*__cplusplus*/
DEFINE_GUID(IID_IDXGIObject,0xaec22fb8,0x76f3,0x4639,0x9b,0xe0,0x28,0xeb,0x43,0xa6,0x7a,0x2e);
DEFINE_GUID(IID_IDXGIDeviceSubObject,0x3d3e0379,0xf9de,0x4d58,0xbb,0x6c,0x18,0xd6,0x29,0x92,0xf1,0xa6);
DEFINE_GUID(IID_IDXGIResource,0x035f3ab4,0x482e,0x4e50,0xb4,0x1f,0x8a,0x7f,0x8b,0xd8,0x96,0x0b);
DEFINE_GUID(IID_IDXGISurface,0xcafcb56c,0x6ac3,0x4889,0xbf,0x47,0x9e,0x23,0xbb,0xd2,0x60,0xec);
DEFINE_GUID(IID_IDXGIAdapter,0x2411e7e1,0x12ac,0x4ccf,0xbd,0x14,0x97,0x98,0xe8,0x53,0x4d,0xc0);
DEFINE_GUID(IID_IDXGIOutput,0xae02eedb,0xc735,0x4690,0x8d,0x52,0x5a,0x8d,0xc2,0x02,0x13,0xaa);
DEFINE_GUID(IID_IDXGISwapChain,0x310d36a0,0xd2e7,0x4c0a,0xaa,0x04,0x6a,0x9d,0x23,0xb8,0x88,0x6a);
DEFINE_GUID(IID_IDXGIFactory,0x7b7166ec,0x21c7,0x44ae,0xb2,0x1a,0xc9,0xae,0x32,0x1a,0xe3,0x69);
DEFINE_GUID(IID_IDXGIDevice,0x54ec77fa,0x1377,0x44e6,0x8c,0x32,0x88,0xfd,0x5f,0x44,0xc8,0x4c);


extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi_0000_0009_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


