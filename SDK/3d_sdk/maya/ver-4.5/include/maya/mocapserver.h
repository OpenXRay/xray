/*
 * *****************************************************************************
 *
 * Copyright (C) 1997-2001 Alias|Wavefront Inc.
 *
 * These coded instructions, statements and computer programs contain
 * unpublished information proprietary to Alias|Wavefront Inc. and are
 * protected by Canadian and US federal copyright laws. They may not be
 * disclosed to third parties or copied or duplicated, in whole or in part,
 * without prior written consent of Alias|Wavefront Inc.
 *
 * Unpublished-rights reserved under the Copyright Laws of the United States.
 *
 * *****************************************************************************
 */

/*
 * mocapserver.h - Definitions for writing motion capture servers for
 *	         Maya
 *
 */

#if !defined(__CAPSERVER_H__)
#define __CAPSERVER_H__ 1

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef _WIN32
#define PROTOTYPES
#endif

/*
 * Use the high level "am i in the devkit" flag to control the rotation
 * order flag
 */
#define CAP_ROTATION_ORDER_MAYA 1
#define CAP_ROTATION_ORDER_KIN  0
#ifndef CAP_ROTATION_ORDER
#	ifdef MAYA_MOCAP_DEVKIT
#		define CAP_ROTATION_ORDER CAP_ROTATION_ORDER_MAYA
#	else
#		define CAP_ROTATION_ORDER CAP_ROTATION_ORDER_KIN
#	endif
#endif

/*
 * Define basic motion capture types
 */

typedef struct _CapChannel *CapChannel;	/* Opaque pointer to a channel */

typedef float CapPosition[3];	/* A 3D position */

typedef float CapQuaternion[4];	/* A quaternion */

typedef float CapMatrix[4][4];	/* A 4x4 matrix */

typedef float CapMatrix3[3][3];	/* A 3x3 matrix */

/*
 * Enumerated types
 */

typedef enum CapSeverity
{
  CAP_SEV_DEBUG,
  CAP_SEV_INFO,
  CAP_SEV_WARNING,
  CAP_SEV_ERROR,
  CAP_SEV_FATAL,
  _CAP_SEV_LAST
} CapSeverity;

/*
 * Note: don't change the order of these.  They match the
 * TrackUsage enum in track.h. (At least UNKNOWN through LENS do.)
 */
typedef enum CapChannelUsage
{
  CAP_USAGE_NONE = -1,
  CAP_USAGE_UNKNOWN,
  CAP_USAGE_POSITION,
  CAP_USAGE_ORIENTATION,
  CAP_USAGE_XPOS,
  CAP_USAGE_YPOS,
  CAP_USAGE_ZPOS,
  CAP_USAGE_XROT,
  CAP_USAGE_YROT,
  CAP_USAGE_ZROT,
  CAP_USAGE_XSCALE,
  CAP_USAGE_YSCALE,
  CAP_USAGE_ZSCALE,
  CAP_USAGE_SCALE,
  CAP_USAGE_ATTACH,
  CAP_USAGE_COUPLING,
  CAP_USAGE_FILEINTERP,
  CAP_USAGE_SHAPE,
  CAP_USAGE_WEIGHT,
  CAP_USAGE_HITHER,
  CAP_USAGE_YON,
  CAP_USAGE_LENS,
  CAP_USAGE_POS_ORIENT,
  _CAP_USAGE_LAST
} CapChannelUsage;

/*
 * Rotation order for converting Euler angles to quaternions
 */
typedef enum CapRotationOrder
{
  /*
   * these rotation orders are kept for backward compatibility
   * and define rotations compatible with Kinemation/TAV naming
   */
  CAP_ROT_XYZ_KIN,
  CAP_ROT_XZY_KIN,
  CAP_ROT_YXZ_KIN,
  CAP_ROT_YZX_KIN,
  CAP_ROT_ZXY_KIN,
  CAP_ROT_ZYX_KIN,

  /*
   * the following rotation order names are reversed from the
   * Kinemation/TAV set but are compatible with PA/Maya names
   */ 

  CAP_ROT_XYZ_MAYA = CAP_ROT_ZYX_KIN,
  CAP_ROT_XZY_MAYA = CAP_ROT_YZX_KIN,
  CAP_ROT_YXZ_MAYA = CAP_ROT_ZXY_KIN,
  CAP_ROT_YZX_MAYA = CAP_ROT_XZY_KIN,
  CAP_ROT_ZXY_MAYA = CAP_ROT_YXZ_KIN,
  CAP_ROT_ZYX_MAYA = CAP_ROT_XYZ_KIN

} CapRotationOrder;

/*
 * This allows us to neither break old code, nor have to rewrite the
 * the entire interface for a consistant "guard_string" implementation
 */
#if CAP_ROTATION_ORDER == CAP_ROTATION_ORDER_MAYA
#	define CAP_ROT_XYZ CAP_ROT_XYZ_MAYA
#	define CAP_ROT_XZY CAP_ROT_XZY_MAYA
#	define CAP_ROT_YXZ CAP_ROT_YXZ_MAYA
#	define CAP_ROT_YZX CAP_ROT_YZX_MAYA
#	define CAP_ROT_ZXY CAP_ROT_ZXY_MAYA
#	define CAP_ROT_ZYX CAP_ROT_ZYX_MAYA
#elif CAP_ROTATION_ORDER == CAP_ROTATION_ORDER_KIN
#	define CAP_ROT_XYZ CAP_ROT_XYZ_KIN
#	define CAP_ROT_XZY CAP_ROT_XZY_KIN
#	define CAP_ROT_YXZ CAP_ROT_YXZ_KIN
#	define CAP_ROT_YZX CAP_ROT_YZX_KIN
#	define CAP_ROT_ZXY CAP_ROT_ZXY_KIN
#	define CAP_ROT_ZYX CAP_ROT_ZYX_KIN
#else
	This compiler error indicates that you have not set a valid
	value for the symbol CAP_ROTATION_ORDER.
#endif

typedef enum CapCommand
{
  CAP_CMD_ERROR,
  CAP_CMD_AUTHORIZE,
  CAP_CMD_INIT,
  CAP_CMD_VERSION,
  CAP_CMD_INFO,
  CAP_CMD_DATA,
  CAP_CMD_START_RECORD,
  CAP_CMD_STOP_RECORD,
  CAP_CMD_CLOSE,
  CAP_CMD_QUIT,
  _CAP_CMD_LAST
} CapCommand;

/*
 * Figure out if we should use prototypes or not
 */

#if defined(PROTOTYPES) || defined(FUNCPROTO) || defined(__STDC__) || defined(__EXTENSIONS__) || defined(__cplusplus)
#define _PROTO(x)	x
#else
#define _PROTO(x)	()
#endif

/*
 * Capture library function declarations/prototypes
 */

int	CapWaitTimeout _PROTO((int fd, int msec));
int	CapDaemonize _PROTO((void));
int	CapError _PROTO((int client_fd, CapSeverity sev, char *pgm,
			 char *fmt,...));
int	CapServe _PROTO((char *server));
int	CapCreateInetSocket _PROTO((char *service, short def_port));
int	CapCreateUnixSocket _PROTO((char *name));
void CapUnlinkUnixSocket(char *name);
CapCommand CapGetCommand _PROTO((int client_fd));
int	CapGetAuthInfo _PROTO((int client_fd, char *ruser, char *rhost,
			       char *realrhost));
int	CapInitialize _PROTO((int client_fd, char *name));
int	CapAuthorize _PROTO((int client_fd, int authorized));
int	CapVersion _PROTO((int client_fd, char *server_name,
			   char *server_version, char *description));
int	CapInfo _PROTO((int client_fd, float min_rate, float max_rate,
			float def_rate, size_t buf_size, int dynamic));
int	CapGetRequestedFrame _PROTO((int client_fd));
float	CapGetRequestedTime _PROTO((int client_fd));
int	CapData _PROTO((int client_fd));
int	CapSetData _PROTO((CapChannel channel, void *data));
int	CapStartRecord _PROTO((int client_fd, float sample_rate,
			       size_t buf_size));
int	CapRecord _PROTO((int client_fd, float time));
int	CapStopRecord _PROTO((int client_fd));
CapChannel CapCreateChannel _PROTO((char *name, CapChannelUsage usage,
				    int data_type));
void	CapQuat2Euler _PROTO((CapRotationOrder order, CapQuaternion q,
			      float *x, float *y, float *z));
void	CapEuler2Quat _PROTO((CapRotationOrder order, float x, float y,
			      float z, CapQuaternion q));
void	CapQuat2Matrix _PROTO((CapQuaternion q, CapMatrix m));
void	CapMatrix2Quat _PROTO((CapMatrix m, CapQuaternion q));
void	CapQuat2Matrix3 _PROTO((CapQuaternion q, CapMatrix3 m));
void	CapMatrix32Quat _PROTO((CapMatrix3 m, CapQuaternion q));
void	CapQuatMult _PROTO((CapQuaternion q1, CapQuaternion q2,
			    CapQuaternion q0));
void	CapQuatRotate _PROTO((CapQuaternion q, CapPosition p,
			      CapPosition r));
float	CapQuatMagnitude _PROTO((CapQuaternion q));
void	CapQuatNormalize _PROTO((CapQuaternion q, CapQuaternion qn));
void	CapQuatInvert _PROTO((CapQuaternion q, CapQuaternion qi));
void	CapEuler2Matrix _PROTO((CapRotationOrder order, float x, float y,
				float z, CapMatrix m));
void	CapEuler2Matrix3 _PROTO((CapRotationOrder order, float x, float y,
				 float z, CapMatrix3 m));
void	CapMatrix2Euler _PROTO((CapRotationOrder ord, CapMatrix m,
				float *x, float *y, float *z));
void	CapMatrix32Euler _PROTO((CapRotationOrder ord, CapMatrix3 m,
				 float *x, float *y, float *z));

float	CapGetRequestedRecordRate _PROTO((int client_fd));
int	CapGetRequestedRecordSize _PROTO((int client_fd));
#define EXPAND_ERROR_BUF 256
extern char   CapExpandErrorMsg[EXPAND_ERROR_BUF];
char   *CapExpandFilename _PROTO((const char *in_name, char *out_name));

#if defined(__cplusplus)
}
#endif

#endif /* __CAPSERVER_H__ */
