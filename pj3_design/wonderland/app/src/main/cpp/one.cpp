#include <jni.h>
#include "mess.h"
#include "checkyeah.h"
#include "aes_simplified.h"

// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("one");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("one")
//      }
//    }

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_one_one_secret(JNIEnv *env, jclass clazz) {
    // TODO: implement secret()

}

//lhl
//javastring to std::string
std::string ToCppString(JNIEnv* env, jstring value) {
    jboolean isCopy;
    const char* c_value = env->GetStringUTFChars(value, &isCopy);
    std::string result(c_value);
    if (isCopy == JNI_TRUE)
        env->ReleaseStringUTFChars(value, c_value);
    return result;
}
//bool to jboolean
jboolean ToJBool(bool value) {
    return value ? JNI_TRUE : JNI_FALSE;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_one_iii_Checkstr(JNIEnv *env, jobject thiz, jstring str) {
    return ToJBool(checkstr(ToCppString(env,str)));
}

//ysh
//Jstring2Cchar*
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
    char*   rtn   =   NULL;
    jclass   clsstring   =   (*env).FindClass("java/lang/String");  //String
    jstring   strencode   =   (*env).NewStringUTF("GB2312"); //"gb2312"
    jmethodID   mid   =   (*env).GetMethodID(clsstring,   "getBytes",   "(Ljava/lang/String;)[B"); //getBytes(Str);
    jbyteArray   barr=   (jbyteArray)(*env).CallObjectMethod(jstr,mid,strencode); // String .getByte("GB2312");
    jsize   alen   =   (*env).GetArrayLength(barr);
    jbyte*   ba   =   (*env).GetByteArrayElements(barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);         //"\0"
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    (*env).ReleaseByteArrayElements(barr,ba,0);  //释放内存空间
    return rtn;
}

//ysh
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_one_ggg_Check(JNIEnv *env, jobject thiz, jstring str) {
    char* flag_=Jstring2CStr(env,str);
    int length=env->GetStringUTFLength(str);
    if (flag_[0] != 'f' || flag_[1] != 'l' || flag_[2] != 'a' || flag_[3] != 'g' || flag_[4] != '{' || flag_[length - 1] != '}'||length>49){
        //str = (jstring) "Wrong format!";
        return -1;
    }
    return (int)djiehiu(flag_);
}
extern "C"
JNIEXPORT jint JNICALL//fake
Java_com_example_one_lll_Checkyeah(JNIEnv *env, jobject thiz, jstring str) {
    char* flag_=Jstring2CStr(env,str);
    int length=env->GetStringUTFLength(str);
    if (flag_[0] != 'f' || flag_[1] != 'l' || flag_[2] != 'a' || flag_[3] != 'g' || flag_[4] != '{' || flag_[length - 1] != '}'){
        //str = (jstring) "Wrong format!";
        return -1;
    }
    return (int)djiehiuyeah(flag_,length);
}
extern "C"
JNIEXPORT jint JNICALL//fake
Java_com_example_one_jjj_Check1(JNIEnv *env, jobject thiz, jstring str) {
    char* flag_=Jstring2CStr(env,str);
    int length=env->GetStringUTFLength(str);
    if (flag_[0] != 'f' || flag_[1] != 'l' || flag_[2] != 'a' || flag_[3] != 'g' || flag_[4] != '{' || flag_[length - 1] != '}'){
        //str = (jstring) "Wrong format!";
        return -1;
    }
    return (int)djiehiuyeah(flag_,length);
}
extern "C"
JNIEXPORT jint JNICALL//fake
Java_com_example_one_kkk_Check2(JNIEnv *env, jobject thiz, jstring str) {
    char* flag_=Jstring2CStr(env,str);
    int length=env->GetStringUTFLength(str);
    if (flag_[0] != 'f' || flag_[1] != 'l' || flag_[2] != 'a' || flag_[3] != 'g' || flag_[4] != '{' || flag_[length - 1] != '}'){
        //str = (jstring) "Wrong format!";
        return -1;
    }
    return (int)djiehiuyeah(flag_,length);
}