#include <jni.h>

#include "mdRightFielder.h"

class Utf8String {
	private:
		JNIEnv* env;
		const char* utf8Ptr;
		jstring jString;
	public:
		Utf8String(JNIEnv* jEnv,jstring str);
		~Utf8String();
		const char* GetUtf8Ptr();
};

Utf8String::Utf8String(JNIEnv* jEnv,jstring str) {
	env=jEnv;
	jString=str;
	utf8Ptr=env->GetStringUTFChars(jString,0);
}

Utf8String::~Utf8String() {
	if (utf8Ptr!=0)
		env->ReleaseStringUTFChars(jString,utf8Ptr);
}

const char* Utf8String::GetUtf8Ptr() {
	if (utf8Ptr!=0)
		return utf8Ptr;
	return "";
}

jstring UnicodeString(JNIEnv* jEnv,const char* str) {
	if (str!=0)
		return jEnv->NewStringUTF(str);
	return jEnv->NewStringUTF("");
}

extern "C" JNIEXPORT jlong JNICALL Java_com_melissadata_mdRightFielderJNI_mdRightFielderCreate(JNIEnv* /*jEnv*/,jclass /*jCls*/) {
	return (jlong) new mdRightFielder();
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_mdRightFielderDestroy(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	delete (mdRightFielder*) I;
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_SetLicenseString(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdRightFielder*) I)->SetLicenseString(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetPathToRightFielderFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	((mdRightFielder*) I)->SetPathToRightFielderFiles(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetBuildNumber(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetBuildNumber());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetDatabaseDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetDatabaseDate());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetLicenseExpirationDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetLicenseExpirationDate());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdRightFielderJNI_InitializeDataFiles(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jint) ((mdRightFielder*) I)->InitializeDataFiles();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetInitializeErrorString(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetInitializeErrorString());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetDelimiter(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jint p1) {
	((mdRightFielder*) I)->SetDelimiter((mdRightFielder::Delimiter) p1);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptFullName(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptFullName(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptDepartment(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptDepartment(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptCompany(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptCompany(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptAddress(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptAddress(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptCityStateZip(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptCityStateZip(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptCountry(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptCountry(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptPhone(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptPhone(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptEmail(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptEmail(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetAcceptURL(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdRightFielder*) I)->SetAcceptURL(p1!=0 ? true : false);
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_SetUserPattern(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1,jstring p2) {
	Utf8String _p1(jEnv,p1);
	Utf8String _p2(jEnv,p2);
	return (jboolean) ((mdRightFielder*) I)->SetUserPattern(_p1.GetUtf8Ptr(),_p2.GetUtf8Ptr());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_Parse(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdRightFielder*) I)->Parse(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_ParseFreeForm(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdRightFielder*) I)->ParseFreeForm(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_ParseFielded(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdRightFielder*) I)->ParseFielded(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetFullName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetFullName());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetFullNameNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetFullNameNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetDepartment(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetDepartment());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetDepartmentNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetDepartmentNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetCompany(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetCompany());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetCompanyNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetCompanyNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetAddress(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetAddress());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetAddress2(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetAddress2());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetAddress3(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetAddress3());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetCity(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetCity());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetState(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetState());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetPostalCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetPostalCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetCountry(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetCountry());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetLastLine(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetLastLine());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetPhone(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetPhone());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetPhoneNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetPhoneNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetPhoneType(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetPhoneType());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetPhoneTypeNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetPhoneTypeNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetEmail(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetEmail());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetEmailNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetEmailNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetURL(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetURL());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetURLNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetURLNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetUserField(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetUserField(_p1.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetUserFieldNext(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdRightFielder*) I)->GetUserFieldNext(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetUnrecognized(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetUnrecognized());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdRightFielderJNI_GetUnrecognizedNext(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jboolean) ((mdRightFielder*) I)->GetUnrecognizedNext();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetResults(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetResults());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetResultCodeDescription(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring resultCode,jint opt) {
	Utf8String _resultCode(jEnv,resultCode);
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetResultCodeDescription(_resultCode.GetUtf8Ptr(),(mdRightFielder::ResultCdDescOpt) opt));
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdRightFielderJNI_SetReserved(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1,jstring p2) {
	Utf8String _p1(jEnv,p1);
	Utf8String _p2(jEnv,p2);
	((mdRightFielder*) I)->SetReserved(_p1.GetUtf8Ptr(),_p2.GetUtf8Ptr());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdRightFielderJNI_GetReserved(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return UnicodeString(jEnv,((mdRightFielder*) I)->GetReserved(_p1.GetUtf8Ptr()));
}

