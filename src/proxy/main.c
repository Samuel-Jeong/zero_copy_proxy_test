#include "local/proxy_l.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief Proxy 구동을 위한 main 함수
 * @return int
 * @param argc 매개변수 개수
 * @param argv ip 와 포트 정보
 */
int main( int argc, char **argv){
	int rv;

	if( argc != 5){
		printf("	| ! need param (total 4) : [local ip] [local port] [host ip] [host port]\n");
		return -1;
	}

	proxy_t *proxy = proxy_instance( argv);
	if( proxy == NULL){
		printf("	| ! Proxy : Fail to initialize\n");
		return -1;
	}
	
	rv = proxy_handle_req( proxy);
	if( rv != SOC_ERR){
		proxy_final( proxy);
	}
}

