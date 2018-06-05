//
// Created by sheldon on 17-1-4.
//
/*
（1）JNIEXPORT ：在Jni编程中所有本地语言实现Jni接口的方法前面都有一个"JNIEXPORT",这个可以看做是Jni的一个标志，至今为止没发现它有什么特殊的用处。

（2）jint ：这个学过编程的人都知道，当然是方法的返回值了。

（3）JNICALL ：这个可以理解为Jni 和Call两个部分，和起来的意思就是 Jni调用XXX（后面的XXX就是JAVA的方法名）。

（4）Java_com_test01_Test_firstTest：这个就是被上一步中被调用的部分，也就是Java中的native 方法名，这里起名字的方式比较特别，是：包名+类名+方法名。

（5）JNIEnv * env：这个env可以看做是Jni接口本身的一个对象，在上一篇中提到的jni.h头文件中存在着大量被封装好的函数，这些函数也是Jni编程中经常被使用到的，要想调用这些函数就需要使用JNIEnv这个对象。例如：env->GetObjectClass()。（详情请查看jni.h）

（6）jobject obj：刚才在Test类的main方法中有这样一段代码:　
*/

/* DO NOT EDIT THIS FILE - it is machine generated */
#include "CarEyeJni.h"
/* Header for class com_hsb_ffmpeg_FFmpegNative */
#include "libavcodec/avcodec.h"
#include "libavcodec/avdct.h"
#include "libavcodec/avfft.h"
#include "libavcodec/dirac.h"
#include "libavcodec/dv_profile.h"
#include "libavcodec/vaapi.h"
#include "libavcodec/version.h"
#include "libavcodec/vorbis_parser.h"
#include "libavdevice/avdevice.h"
#include "libavdevice/version.h"
#include "libavfilter/avfilter.h"
#include "libavfilter/avfiltergraph.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
#include "libavfilter/version.h"
#include "libavformat/avformat.h"
#include "libavformat/avio.h"
#include "libavformat/version.h"
#include "libavutil/adler32.h"
#include "libavutil/aes_ctr.h"
#include "libavutil/aes.h"
#include "libavutil/attributes.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/avconfig.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/base64.h"
#include "libavutil/blowfish.h"
#include "libavutil/bprint.h"
#include "libavutil/bswap.h"
#include "libavutil/buffer.h"
#include "libavutil/camellia.h"
#include "libavutil/cast5.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/crc.h"
#include "libavutil/des.h"
#include "libavutil/dict.h"
#include "libavutil/display.h"
#include "libavutil/downmix_info.h"
#include "libavutil/error.h"
#include "libavutil/eval.h"
#include "libavutil/ffversion.h"
#include "libavutil/fifo.h"
#include "libavutil/file.h"
#include "libavutil/frame.h"
#include "libavutil/hash.h"
#include "libavutil/hmac.h"
#include "libavutil/imgutils.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lfg.h"
#include "libavutil/log.h"
#include "libavutil/lzo.h"
#include "libavutil/macros.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/mathematics.h"
#include "libavutil/md5.h"
#include "libavutil/mem.h"
#include "libavutil/motion_vector.h"
#include "libavutil/murmur3.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixelutils.h"
#include "libavutil/pixfmt.h"
#include "libavutil/random_seed.h"
#include "libavutil/rational.h"
#include "libavutil/rc4.h"
#include "libavutil/replaygain.h"
#include "libavutil/ripemd.h"
#include "libavutil/samplefmt.h"
#include "libavutil/sha.h"
#include "libavutil/sha512.h"
#include "libavutil/stereo3d.h"
#include "libavutil/tea.h"
#include "libavutil/threadmessage.h"
#include "libavutil/time.h"
#include "libavutil/timecode.h"
#include "libavutil/timestamp.h"
#include "libavutil/tree.h"
#include "libavutil/twofish.h"
#include "libavutil/version.h"
#include "libavutil/xtea.h"
#include "libswresample/swresample.h"
#include "libswresample/version.h"
#include "libswscale/swscale.h"
#include "libswscale/version.h"
#include "CarEyeTypes.h"
#include "CarEyeEncoderAPI.h"
#include "CarEyeOSDAPI.h"
#include "CarEyeDecoderAPI.h"
#include "public.h"

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_ffmpeg_1h264
  (JNIEnv* env, jobject obj, jint codecID)
 {
    AVCodec* codec = NULL;
    av_register_all();//该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    codec = avcodec_find_decoder(codecID);//通过code ID查找一个已经注册的音视频编码器。H264的codecID是28，所以我们java那边传28下来如果检测到H264注册过了这边codec就不为空，返回0
    if(codec != NULL){
      return 0;
    }else{
      return -1;
    }
}

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_CarEyeMPEGInit(JNIEnv* env, jobject obj)
{	
	CarEye_MPEG_Init();
	return 0;
}

JNIEXPORT jlong JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_OpenOSD(JNIEnv* env, jobject obj, jint width, jint height, jint startX, jint startY, jint FontSize,  jint color, jstring  filename, jstring content  )
{
    char* Name;
    char* pContent;
    void*  ret;
    CarEye_OSDParam para;
    para.X = startX;
    para.Y = startY;
    para.Width = width;
    para.Height = height;
   	para.FontSize = FontSize;
   	para.FontColor = color;
   	para.FramesPerSecond = 25;
    Name=(*env)->GetStringUTFChars(env,filename, JNI_FALSE);
    pContent=(*env)->GetStringUTFChars(env,content, JNI_FALSE);
   	strcpy(para.FontName, Name);
   	strcpy(para.SubTitle, pContent);	
   	para.Transparency = 0.7;	 
   	(*env)->ReleaseStringUTFChars(env, filename, Name);
    (*env)->ReleaseStringUTFChars(env, content, pContent);   	      	
   	ret = 	CarEye_OSD_Create(&para);
   	   
}

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_CloseOSD(JNIEnv* env, jobject obj, jlong handle)
{		
	void* pHandle;
    if(handle==0)
        return -1;
    pHandle = (void*)handle;
    CarEye_OSD_Release(pHandle);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_AddOSD(JNIEnv* env, jobject obj, jlong handle, jbyteArray frame, jstring txtoverlay)
{
    unsigned char * pBuffer;
    int ret;
    char* txt;
    void* pHandle;
     if(handle==0)
        return -1;
    pHandle = (void*)handle;
    CarEye_YUVFrame yuv_frame;
    pBuffer = (*env)->GetByteArrayElements(env,frame, 0 );
    int len = (*env)->GetArrayLength(env,frame);     
    yuv_frame.Y = pBuffer;
    yuv_frame.YSize = len*2/3;
    yuv_frame.U = &pBuffer[len*2/3];
    yuv_frame.USize = len/6;
    yuv_frame.V = &pBuffer[len*5/6];
    yuv_frame.VSize = len/6;
    txt = (*env)->GetStringUTFChars(env,txtoverlay, JNI_FALSE);
   // strcpy(gFliter.para.SubTitle, txt);	   
    ret = CarEye_OSD_Encode(pHandle,&yuv_frame, txt);        
   (*env)->ReleaseStringUTFChars(env, txtoverlay, txt);     
   (*env)->ReleaseByteArrayElements(env,frame,pBuffer,0);
   return ret;
}



JNIEXPORT jlong JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_CreateEncode(JNIEnv* env, jobject obj, jobject para) {
    void*  ret;
    CarEye_OriginalStream param;
    jclass jcInfo = (*env)->GetObjectClass(env, para);
    if (0 == jcInfo) {
        CarEyeLog("GetObjectClass returned 0\n");
        return 0;
    }
    int fps = (*env)->GetIntField(env, para, (*env)->GetFieldID(env, jcInfo, "fps", "I"));
    int InVedioType = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "InVedioType", "I"));
    int OutVedioType =(*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "OutVedioType", "I"));
    int width = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "width", "I"));
    int height =  (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "height", "I"));
    int VideoBitrate = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "VideoBitrate", "I"));
    int InputAuidoType = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "InputAuidoType", "I"));
    int OutAudioType = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "OutAudioType", "I"));
    int SampleRate = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "SampleRate", "I"));
    int AudioBitrate=(*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "AudioBitrate", "I"));
    CarEyeLog("fps:%d", fps);
    CarEyeLog("InVedioType:%d", InVedioType);
    CarEyeLog("width:%d,VideoBitrate:%d,OutVedioType:%d ", width,VideoBitrate,OutVedioType);
    param.AudioBitrate = AudioBitrate;
    param.InVideoType = InVedioType;
    param.OutAudioType = OutAudioType;
    param.OutVideoType = OutVedioType;
    param.FramesPerSecond = fps;
    param.GopSize = 10;
    param.MaxBFrames =1;
    param.Width = width;
    param.Height = height;
    param.VideoBitrate =VideoBitrate;
    param.SampleRate = SampleRate;
    ret = CarEye_EncoderCreate(param);
    if(  ret  == NULL) {
        return 0;
    }else
    {
        return (long)ret;
    }
}

JNIEXPORT jlong JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_CreateDecode(JNIEnv* env, jobject obj, jobject para) {
	
	 void*  ret;
   CarEye_FrameInfo param;
   jclass jcInfo = (*env)->GetObjectClass(env, para);
   if (0 == jcInfo) {
        CarEyeLog("GetObjectClass returned 0\n");
        return 0;
   }
  int VCodec = (*env)->GetIntField(env, para, (*env)->GetFieldID(env, jcInfo, "VCodec", "I"));
  int ACodec = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "ACodec", "I"));
  int FramesPerSecond =(*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "FramesPerSecond", "I"));
  int Width = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "width", "I"));
  int Height =  (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "height", "I"));
  int VideoBitrate = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "VideoBitrate", "I"));
  int SampleRate = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "SampleRate", "I"));
  int Channels = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "Channels", "I"));
  int BitsPerSample = (*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "BitsPerSample", "I"));
  int AudioBitrate=(*env)->GetIntField(env, para,(*env)->GetFieldID(env, jcInfo, "AudioBitrate", "I"));  
  param.VCodec = VCodec;
  param.ACodec = ACodec;
  param.Width = Width;
  param.Height = Height;
  param.VideoBitrate = VideoBitrate;
  param.SampleRate = SampleRate;
  param.Channels = Channels;
  param.BitsPerSample = BitsPerSample;
  param.AudioBitrate = AudioBitrate;
  ret = CarEye_DecoderCreate( param);
  if(  ret  == NULL) {
      return 0;
  }else
  {
      return (long)ret;
  } 
	
}

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_Encode(JNIEnv* env, jobject obj, jlong handle,jint flag,jint pts, jbyteArray frame, jbyteArray OutFrame) {
    void* pHandle;
    int ret;
    unsigned char* in_data;
    unsigned char* out_data;
    
    if(handle==0)
        return -1;
    pHandle = (void*)handle;
    in_data = (*env)->GetByteArrayElements(env,frame, 0 );
    int len = (*env)->GetArrayLength(env,frame);
    out_data = (*env)->GetByteArrayElements(env,OutFrame, 0 );
  
    if(flag  == 0)//0 vedio 1: audio
    {    
    	CarEye_YUVFrame yuv_frame;
		  yuv_frame.Y = in_data;
	    yuv_frame.YSize = len*2/3;
	    yuv_frame.U = &in_data[len*2/3];
	    yuv_frame.USize = len/6;
	    yuv_frame.V = &in_data[len*5/6];
	    yuv_frame.VSize = len/6;
    	ret =  CarEye_EncoderYUV(pHandle,  &yuv_frame,pts, out_data );
    }else
    {
			ret =  CarEye_EncoderPCM(pHandle,  in_data,len, pts, out_data );
    }
    (*env)->ReleaseByteArrayElements(env,frame,in_data,0);
    (*env)->ReleaseByteArrayElements(env,OutFrame,out_data,0);
    return ret;
}

JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_Decode(JNIEnv* env, jobject obj, jlong handle,jint flag, jbyteArray frame, jbyteArray OutFrame) {
    void* pHandle;
    int ret;
    unsigned char* in_data;
    unsigned char* out_data;
    CarEye_YUVFrame yuv_frame;
    if(handle==0)
        return -1;
    pHandle = (void*)handle;
    in_data = (*env)->GetByteArrayElements(env,frame, 0 );
    int len = (*env)->GetArrayLength(env,frame);
    out_data = (*env)->GetByteArrayElements(env,OutFrame, 0 );    
    if( flag == 0)
		{
			ret = CarEye_DecoderYUV420(pHandle, in_data, len, out_data);
		}else
		{
			CarEye_DecoderPCM(pHandle, in_data, len, out_data);
		} 
		(*env)->ReleaseByteArrayElements(env,frame,in_data,0);
    (*env)->ReleaseByteArrayElements(env,OutFrame,out_data,0);
    
    return ret;
}



JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_ReleaseEncode(JNIEnv* env, jobject obj, jlong handle) {
    void* pHandle;
    if(handle==0)
        return -1;
    pHandle = (void*)handle;
    CarEye_EncoderRelease(pHandle);
    return 0;
}



JNIEXPORT jint JNICALL Java_com_CarEye_CarEyelib_ffmpegandroid_FFmpegNative_ReleaseDecode(JNIEnv* env, jobject obj, jlong handle) {
    void* pHandle;
    if(handle==0)
        return -1;
    pHandle = (void*)handle;
    CarEye_DecoderRelease(pHandle);
    return 0;
}


