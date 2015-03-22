
extern zend_class_entry *phalconry_mvc_module_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module);

PHP_METHOD(Phalconry_Mvc_Module, getDI);
PHP_METHOD(Phalconry_Mvc_Module, __get);
PHP_METHOD(Phalconry_Mvc_Module, setName);
PHP_METHOD(Phalconry_Mvc_Module, getName);
PHP_METHOD(Phalconry_Mvc_Module, setApp);
PHP_METHOD(Phalconry_Mvc_Module, getApp);
PHP_METHOD(Phalconry_Mvc_Module, isLoaded);
PHP_METHOD(Phalconry_Mvc_Module, isPrimary);
PHP_METHOD(Phalconry_Mvc_Module, isDefault);
PHP_METHOD(Phalconry_Mvc_Module, registerAutoloaders);
PHP_METHOD(Phalconry_Mvc_Module, getControllerNamespace);
PHP_METHOD(Phalconry_Mvc_Module, onLoad);
PHP_METHOD(Phalconry_Mvc_Module, onView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setapp, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_onview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\View, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_module_method_entry) {
	PHP_ME(Phalconry_Mvc_Module, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, __get, arginfo_phalconry_mvc_module___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, setName, arginfo_phalconry_mvc_module_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, setApp, arginfo_phalconry_mvc_module_setapp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getApp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isLoaded, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, registerAutoloaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getControllerNamespace, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, onLoad, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, onView, arginfo_phalconry_mvc_module_onview, ZEND_ACC_PUBLIC)
  PHP_FE_END
};