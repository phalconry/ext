
extern zend_class_entry *phalconry_mvc_application_handlerinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_HandlerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_handlerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_handlerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Application_HandlerInterface, handle, arginfo_phalconry_mvc_application_handlerinterface_handle)
	PHP_FE_END
};