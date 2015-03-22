
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * Module
 *
 * This class is "pseudo-DI-aware" in that its getDI() method returns the
 * default DI container using DI::getDefault()
 */
ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc, Module, phalconry, mvc_module, phalconry_mvc_module_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * The module name
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The application
	 * @var \Phalconry\Mvc\Application
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_module_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\mvc\\moduledefinitioninterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Returns the DI container
 *
 * @return \Phalcon\DiInterface
 */
PHP_METHOD(Phalconry_Mvc_Module, getDI) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *phalcon_phalcon_di;

	ZEPHIR_MM_GROW();

	phalcon_phalcon_di = zend_fetch_class(SL("\\Phalcon\\DI"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_phalcon_di, "getdefault", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a shared item from the DI container
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_Module, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "getshared", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the module name
 *
 * @param string $name
 */
PHP_METHOD(Phalconry_Mvc_Module, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the module name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Module, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the application
 *
 * @param \Phalconry\Mvc\Application $app
 */
PHP_METHOD(Phalconry_Mvc_Module, setApp) {

	zval *app;

	zephir_fetch_params(0, 1, 0, &app);



	if (!(zephir_instance_of_ev(app, phalconry_mvc_application_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalconry\\Mvc\\Application'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_application"), app TSRMLS_CC);

}

/**
 * Returns the application
 *
 * @return \Phalconry\Mvc\Application
 * @throws \RuntimeException if app is not set
 */
PHP_METHOD(Phalconry_Mvc_Module, getApp) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_application"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Module is not active", "phalconry/mvc/module.zep", 79);
		return;
	}
	RETURN_MM_MEMBER(this_ptr, "_application");

}

/**
 * Whether the module has been loaded
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isLoaded) {


	RETURN_BOOL(zephir_isset_property(this_ptr, SS("_application") TSRMLS_CC));

}

/**
 * Whether this is the primary module
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isPrimary) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isloaded", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getapp", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, _1, "getprimarymodule", NULL);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(this_ptr, _2));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Whether this is the default module
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isDefault) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isloaded", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getname", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getapp", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, _2, "getdefaultmodule", NULL);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_1, _3));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Register separate autoloaders for the module, if any
 */
PHP_METHOD(Phalconry_Mvc_Module, registerAutoloaders) {



}

/**
 * Returns the default namespace to use for controllers
 *
 * Called in Application on "application:afterStartModule"
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Module, getControllerNamespace) {

}

/**
 * Allows the module to perform start-up tasks
 *
 * Called in Application on "application:afterStartModule"
 */
PHP_METHOD(Phalconry_Mvc_Module, onLoad) {



}

/**
 * Allows the PRIMARY module to perform additional operations when responding with a view
 *
 * Called in Application on "application:afterHandleRequest"
 * ONLY IF respondse mode is 'view' - otherwise, the view is disabled
 *
 * @param \Phalcon\Mvc\View $view
 */
PHP_METHOD(Phalconry_Mvc_Module, onView) {

	zval *view;

	zephir_fetch_params(0, 1, 0, &view);



	if (!(zephir_instance_of_ev(view, zephir_get_internal_ce(SS("phalcon\\mvc\\view") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'view' must be an instance of 'Phalcon\\Mvc\\View'", "", 0);
		return;
	}

}
