#ifndef DUMP_WRAP_H_
#define DUMP_WRAP_H_


#include <stdint.h>

/*  
 *  ������
 */
#define BFDWRAP_ERR_FILE                50
#define BFDWRAP_ERR_DISASM              70

#define BFDWRAP_ERR_FILE_SZ             (BFDWRAP_ERR_FILE+1)    /*  �ļ���С����            */
#define BFDWRAP_ERR_FILE_NOFOUND        (BFDWRAP_ERR_FILE+2)    /*  �ļ�������              */
#define BFDWRAP_ERR_FILE_OPEN           (BFDWRAP_ERR_FILE+3)    /*  �ļ���ʧ��            */
#define BFDWRAP_ERR_FILE_MODE           (BFDWRAP_ERR_FILE+4)    /*  �ļ���ʽ����            */
#define BFDWRAP_ERR_FILE_UNSUPPORT      (BFDWRAP_ERR_FILE+5)    /*  ��֧���������͵��ļ�    */
#define BFDWRAP_ERR_FILE_MULTIRECOG     (BFDWRAP_ERR_FILE+6)    /*   ��Ҫָ����ʽ           */
#define BFDWRAP_ERR_FILE_BADFMT         (BFDWRAP_ERR_FILE+7)    /*   �ļ���ʽ����           */
#define BFDWRAP_ERR_FILE_LOADERR        (BFDWRAP_ERR_FILE+8)    /*   ������Ϣʧ��           */



#define BFDWRAP_ERR_DISASM_NOFUNC       (BFDWRAP_ERR_DISASM+1)    /*  û�з���ຯ��        */
#define BFDWRAP_ERR_DISASM_NOARCH       (BFDWRAP_ERR_DISASM+2)    /*  û���ҵ��ܹ�          */
#define BFDWRAP_ERR_DISASM_NOSIZE       (BFDWRAP_ERR_DISASM+3)    /*  ��ȡsize��Ϣʧ��      */
#define BFDWRAP_ERR_DISASM_NODYMRELSZ   (BFDWRAP_ERR_DISASM+4)    /*  û���ҵ���Ӧ�Ķ�̬������ */

#define BFDWRAP_ERR_NO_MEM              20  /*  û���ڴ�        */
#define BFDWRAP_ERR_ARG                 21  /*  ��������        */
#define BFDWRAP_ERR_NOFOUND             22  /*  û���ҵ�        */



/*
 *  ��������
 */
#define BFDWRAP_MAX_PATH                256 /*  �ļ�·������    */
#define BFDWRAP_FUNC_LEN                32  /*  ����������      */

#ifndef DASM_ADDR_T
#define DASM_ADDR_T
typedef int64_t  dasm_addr_t;
#endif


enum EDumpWrapAct{
    EDumpWrapBegin  = 0,        //  ��ʼ����
    EDumpWrapEnd,               //  �����ļ����
    EDumpWrapFuncStart,         //  ��ʼ�������
    EDumpWrapFuncEnd            //  �����������
};
/** 
 * @brief ���¼�д�ӡ��Ϣ
 * 
 * @param param     [in]    ����˽�в���
 * @param buf       [in]    ���������
 * @param size      [in]    ������ݴ�С
 * 
 * @return д����ַ���
 */

typedef unsigned int (*DASM_DUMP_CALLBACK)(void *param,const char *buf,int len);
typedef unsigned int (*DASM_DUMPFMT_CALLBACK)(void *param,const char *fmt,...);

/** 
 * @brief ������һ������Ϊ
 * 
 * @param param     [in]    ����˽�в���
 * @param newact    [in]    �������Ϊ����
 * @param fname     [in]    ��ǰ�����elf�ļ���
 * @param elfoffset [in]    �ļ�ƫ��
 * @param funcname  [in]    ������
 * @param code_start [in]   ������������ʼ
 * @param code_end   [in]   �������������
 * 
 * @return  0       ����Ҫ��¼
 *          ����ֵ  ϣ��֪��������ĳ��pc��Զ�Ӧ�Ĵ�����
 */
typedef dasm_addr_t    (*DASM_ACT_CHECK)(void *param,
            enum EDumpWrapAct newact,
            const char *fname,dasm_addr_t elfoffset,
            const char *funcname,
            dasm_addr_t    code_start,
            dasm_addr_t    code_end);




/** 
 * @brief objdump��װ�ӿ�
 * 
 * @param hctl          [out]   ����ص�,ͬʱ��filename�ֶ��д�����������ļ���
 * 
 * @return 0:   �����ɹ�
 *          ����ֵ: ������
 */
int dumpwrap_load(
        const char      *fname,     //  �ļ���
        int             fsize,      //  �ļ���С,0��ʾ��У��
        dasm_addr_t    vma_offset, //  �ļ���ÿ�����ŵ�ƫ��
        DASM_DUMP_CALLBACK dump,   //  ���������ص�
        DASM_DUMPFMT_CALLBACK err, //  ��������ص�
        DASM_ACT_CHECK     act,    //  ����ת���ص�
        void *param );              //  �����ص��Ĳ���
//typedef void *bfdwrap_t;
//bfdwrap_t dumpwrap_open_elf(const char *file_name,int *err,dasm_addr_t vma_offset);
//int dumpwrap_dump_elf(bfdwrap_t handle,int showline,struct dumpwrap_ctl *hout);
//void dumpwrap_close_elf(bfdwrap_t handle);



#endif

