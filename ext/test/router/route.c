
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


/**
 * Test\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Test_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Test\\Router, Route, test, router_route, test_router_route_method_entry, 0);

	zend_declare_property_null(test_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_router_route_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Test\Router\Route constructor
 *
 * @param string pattern
 * @param array paths
 * @param array|string httpMethods
 */
PHP_METHOD(Test_Router_Route, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern, *paths = NULL, *httpMethods = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern, &paths, &httpMethods);

	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reconfigure", NULL, pattern, paths);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string pattern
 * @return string
 */
PHP_METHOD(Test_Router_Route, compilePattern) {

	zval *pattern = NULL, *idPattern, *_0 = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern);

	ZEPHIR_SEPARATE_PARAM(pattern);


	if (zephir_memnstr_str(pattern, SL(":"), "test/router/route.zep", 56)) {
		ZEPHIR_INIT_VAR(idPattern);
		ZVAL_STRING(idPattern, "/([a-zA-Z0-9\\_\\-]+)", 1);
		if (zephir_memnstr_str(pattern, SL("/:module"), "test/router/route.zep", 62)) {
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "/:module", 0);
			zephir_fast_str_replace(_0, &_1, idPattern, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
		if (zephir_memnstr_str(pattern, SL("/:controller"), "test/router/route.zep", 67)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "/:controller", 0);
			zephir_fast_str_replace(_0, &_1, idPattern, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
		if (zephir_memnstr_str(pattern, SL("/:namespace"), "test/router/route.zep", 72)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "/:namespace", 0);
			zephir_fast_str_replace(_0, &_1, idPattern, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
		if (zephir_memnstr_str(pattern, SL("/:action"), "test/router/route.zep", 77)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "/:action", 0);
			zephir_fast_str_replace(_0, &_1, idPattern, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
		if (zephir_memnstr_str(pattern, SL("/:params"), "test/router/route.zep", 82)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "/:params", 0);
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_STRING(&_2, "(/.*)*", 0);
			zephir_fast_str_replace(_0, &_1, &_2, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
		if (zephir_memnstr_str(pattern, SL("/:int"), "test/router/route.zep", 87)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "/:int", 0);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "/([0-9]+)", 0);
			zephir_fast_str_replace(_0, &_1, &_2, pattern);
			ZEPHIR_CPY_WRT(pattern, _0);
		}
	}
	if (zephir_memnstr_str(pattern, SL("("), "test/router/route.zep", 93)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", pattern, "$#");
		RETURN_MM();
	}
	if (zephir_memnstr_str(pattern, SL("["), "test/router/route.zep", 98)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", pattern, "$#");
		RETURN_MM();
	}
	RETURN_CCTOR(pattern);

}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 *<code>
 * $route->via('GET');
 * $route->via(array('GET', 'POST'));
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, via) {

	zval *httpMethods;

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_this(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Extracts parameters from a string
 *
 * @param string pattern
 */
PHP_METHOD(Test_Router_Route, extractNamedParams) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	long _0, _6, _23;
	zend_bool notValid = 0, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18;
	int tmp, cursor, cursorVar, marker, bracketCount = 0, parenthesesCount = 0, foundPattern = 0, intermediate = 0, numberMatches = 0, ZEPHIR_LAST_CALL_STATUS;
	char ch;
	zval *pattern_param = NULL, *matches, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, *_19 = NULL, *_21 = NULL, *_24 = NULL;
	zval *pattern = NULL, *route, *item = NULL, *variable = NULL, *regexp = NULL, *_5 = NULL, *_20 = NULL, *_22 = NULL, *_25 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	zephir_get_strval(pattern, pattern_param);


	if (zephir_fast_strlen_ev(pattern) <= 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(route);
	ZVAL_EMPTY_STRING(route);
	for (_0 = 0; _0 < Z_STRLEN_P(pattern); _0++) {
		cursor = _0; 
		ch = ZEPHIR_STRING_OFFSET(pattern, _0);
		if (parenthesesCount == 0) {
			if (ch == '{') {
				if (bracketCount == 0) {
					marker = (cursor + 1);
					intermediate = 0;
					notValid = 0;
				}
				bracketCount++;
			} else {
				if (ch == '}') {
					bracketCount--;
					if (intermediate > 0) {
						if (bracketCount == 0) {
							numberMatches++;
							ZEPHIR_INIT_NVAR(variable);
							ZVAL_EMPTY_STRING(variable);
							ZEPHIR_INIT_NVAR(regexp);
							ZVAL_EMPTY_STRING(regexp);
							ZEPHIR_SINIT_NVAR(_1);
							ZVAL_LONG(&_1, marker);
							ZEPHIR_SINIT_NVAR(_2);
							ZVAL_LONG(&_2, (cursor - marker));
							ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, pattern, &_1, &_2);
							zephir_check_call_status();
							zephir_get_strval(_5, _3);
							ZEPHIR_CPY_WRT(item, _5);
							for (_6 = 0; _6 < Z_STRLEN_P(item); _6++) {
								cursorVar = _6; 
								ch = ZEPHIR_STRING_OFFSET(item, _6);
								if (ch == '\0') {
									break;
								}
								_7 = cursorVar == 0;
								if (_7) {
									_8 = ch >= 'a';
									if (_8) {
										_8 = ch <= 'z';
									}
									_9 = _8;
									if (!(_9)) {
										_10 = ch >= 'A';
										if (_10) {
											_10 = ch <= 'Z';
										}
										_9 = _10;
									}
									_7 = !_9;
								}
								if (_7) {
									notValid = 1;
									break;
								}
								_11 = ch >= 'a';
								if (_11) {
									_11 = ch <= 'z';
								}
								_12 = _11;
								if (!(_12)) {
									_13 = ch >= 'A';
									if (_13) {
										_13 = ch <= 'Z';
									}
									_12 = _13;
								}
								_14 = _12;
								if (!(_14)) {
									_15 = ch >= '0';
									if (_15) {
										_15 = ch <= '9';
									}
									_14 = _15;
								}
								_16 = _14;
								if (!(_16)) {
									_16 = ch == '-';
								}
								_17 = _16;
								if (!(_17)) {
									_17 = ch == '_';
								}
								_18 = _17;
								if (!(_18)) {
									_18 = ch == ':';
								}
								if (_18) {
									if (ch == ':') {
										ZEPHIR_SINIT_NVAR(_1);
										ZVAL_LONG(&_1, 0);
										ZEPHIR_SINIT_NVAR(_2);
										ZVAL_LONG(&_2, cursorVar);
										ZEPHIR_CALL_FUNCTION(&_19, "substr", &_4, item, &_1, &_2);
										zephir_check_call_status();
										zephir_get_strval(_20, _19);
										ZEPHIR_CPY_WRT(variable, _20);
										ZEPHIR_SINIT_NVAR(_1);
										ZVAL_LONG(&_1, (cursorVar + 1));
										ZEPHIR_CALL_FUNCTION(&_21, "substr", &_4, item, &_1);
										zephir_check_call_status();
										zephir_get_strval(_22, _21);
										ZEPHIR_CPY_WRT(regexp, _22);
										break;
									}
								} else {
									notValid = 1;
									break;
								}
							}
							if (!(notValid)) {
								tmp = numberMatches;
								_7 = zephir_is_true(variable);
								if (_7) {
									_7 = zephir_is_true(regexp);
								}
								if (_7) {
									foundPattern = 0;
									for (_23 = 0; _23 < Z_STRLEN_P(regexp); _23++) {
										ch = ZEPHIR_STRING_OFFSET(regexp, _23);
										if (ch == '\0') {
											break;
										}
										if (!(foundPattern)) {
											if (ch == '(') {
												foundPattern = 1;
											}
										} else {
											if (ch == ')') {
												foundPattern = 2;
												break;
											}
										}
									}
									if (foundPattern != 2) {
										zephir_concat_self_str(&route, "(", sizeof("(")-1 TSRMLS_CC);
										zephir_concat_self(&route, regexp TSRMLS_CC);
										zephir_concat_self_str(&route, ")", sizeof(")")-1 TSRMLS_CC);
									} else {
										zephir_concat_self(&route, regexp TSRMLS_CC);
									}
									ZEPHIR_INIT_NVAR(_24);
									ZVAL_LONG(_24, tmp);
									zephir_array_update_zval(&matches, variable, &_24, PH_COPY | PH_SEPARATE);
								} else {
									zephir_concat_self_str(&route, "([^/]*)", sizeof("([^/]*)")-1 TSRMLS_CC);
									ZEPHIR_INIT_NVAR(_24);
									ZVAL_LONG(_24, tmp);
									zephir_array_update_zval(&matches, item, &_24, PH_COPY | PH_SEPARATE);
								}
							} else {
								ZEPHIR_INIT_LNVAR(_25);
								ZEPHIR_CONCAT_SVS(_25, "{", item, "}");
								zephir_concat_self(&route, _25 TSRMLS_CC);
							}
							continue;
						}
					}
				}
			}
		}
		if (bracketCount == 0) {
			if (ch == '(') {
				parenthesesCount++;
			} else {
				if (ch == ')') {
					parenthesesCount--;
					if (parenthesesCount == 0) {
						numberMatches++;
					}
				}
			}
		}
		if (bracketCount > 0) {
			intermediate++;
		} else {
			zephir_concat_self_char(&route, ch TSRMLS_CC);
		}
	}
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, route);
	zephir_array_fast_append(return_value, matches);
	RETURN_MM();

}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string pattern
 * @param array paths
 */
PHP_METHOD(Test_Router_Route, reConfigure) {

	int _0, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern, *paths = NULL, *moduleName = NULL, *controllerName = NULL, *actionName = NULL, *parts, *routePaths = NULL, *realClassName = NULL, *namespaceName, *pcrePattern = NULL, *compiledPattern = NULL, *extracted = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(pattern) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The pattern must be string");
		return;
	}
	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_INIT_VAR(moduleName);
			ZVAL_NULL(moduleName);
			ZEPHIR_INIT_VAR(controllerName);
			ZVAL_NULL(controllerName);
			ZEPHIR_INIT_VAR(actionName);
			ZVAL_NULL(actionName);
			ZEPHIR_INIT_VAR(parts);
			zephir_fast_explode_str(parts, SL("::"), paths, LONG_MAX TSRMLS_CC);
			do {
				_0 = zephir_fast_count_int(parts TSRMLS_CC);
				if (_0 == 3) {
					ZEPHIR_OBS_NVAR(moduleName);
					zephir_array_fetch_long(&moduleName, parts, 0, PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 1, PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 2, PH_NOISY TSRMLS_CC);
					break;
				}
				if (_0 == 2) {
					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 0, PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 1, PH_NOISY TSRMLS_CC);
					break;
				}
				if (_0 == 1) {
					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 0, PH_NOISY TSRMLS_CC);
					break;
				}
			} while(0);

			ZEPHIR_INIT_VAR(routePaths);
			array_init(routePaths);
			if (Z_TYPE_P(moduleName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(controllerName) != IS_NULL) {
				if (zephir_memnstr_str(controllerName, SL("\\"), "test/router/route.zep", 310)) {
					ZEPHIR_INIT_VAR(realClassName);
					zephir_get_class_ns(realClassName, controllerName, 0 TSRMLS_CC);
					ZEPHIR_INIT_VAR(namespaceName);
					zephir_get_ns_class(namespaceName, controllerName, 0 TSRMLS_CC);
					if (zephir_is_true(namespaceName)) {
						zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CPY_WRT(realClassName, controllerName);
				}
				ZEPHIR_INIT_VAR(_1);
				zephir_uncamelize(_1, realClassName);
				zephir_array_update_string(&routePaths, SL("controller"), &_1, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(actionName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_CPY_WRT(routePaths, paths);
		}
	} else {
		ZEPHIR_INIT_NVAR(routePaths);
		array_init(routePaths);
	}
	if (Z_TYPE_P(routePaths) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The route contains invalid paths");
		return;
	}
	if (!(zephir_start_with_str(pattern, SL("#")))) {
		if (zephir_memnstr_str(pattern, SL("{"), "test/router/route.zep", 348)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, pattern);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(pcrePattern);
			zephir_array_fetch_long(&pcrePattern, extracted, 0, PH_NOISY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_1);
			zephir_array_fetch_long(&_2, extracted, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_fast_array_merge(_1, &(routePaths), &(_2) TSRMLS_CC);
			ZEPHIR_CPY_WRT(routePaths, _1);
		} else {
			ZEPHIR_CPY_WRT(pcrePattern, pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, pcrePattern);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(compiledPattern, pattern);
	}
	zephir_update_property_this(this_ptr, SL("_pattern"), pattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_compiledPattern"), compiledPattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_paths"), routePaths TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the route's name
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the route's name
 *
 *<code>
 * $router->add('/about', array(
 *     'controller' => 'about'
 * ))->setName('about');
 *</code>
 *
 * @param string name
 * @return Route
 */
PHP_METHOD(Test_Router_Route, setName) {

	zval *name;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treaded as not matched
 *
 * @param callback callback
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, beforeMatch) {

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_this(this_ptr, SL("_beforeMatch"), callback TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 *
 * @return mixed
 */
PHP_METHOD(Test_Router_Route, getBeforeMatch) {


	RETURN_MEMBER(this_ptr, "_beforeMatch");

}

/**
 * Returns the route's id
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getRouteId) {


	RETURN_MEMBER(this_ptr, "_id");

}

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getPattern) {


	RETURN_MEMBER(this_ptr, "_pattern");

}

/**
 * Returns the route's compiled pattern
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getCompiledPattern) {


	RETURN_MEMBER(this_ptr, "_compiledPattern");

}

/**
 * Returns the paths
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getPaths) {


	RETURN_MEMBER(this_ptr, "_paths");

}

/**
 * Returns the paths using positions as keys and names as values
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getReversedPaths) {

	HashTable *_2;
	HashPosition _1;
	zval *reversed, *path = NULL, *position = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(reversed);
	array_init(reversed);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_paths"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(path, _2, _1);
		ZEPHIR_GET_HVALUE(position, _3);
		zephir_array_update_zval(&reversed, position, &path, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(reversed);

}

/**
 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
 *
 *<code>
 * $route->setHttpMethods('GET');
 * $route->setHttpMethods(array('GET', 'POST'));
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, setHttpMethods) {

	zval *httpMethods;

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_this(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the HTTP methods that constraint matching the route
 *
 * @return string|array
 */
PHP_METHOD(Test_Router_Route, getHttpMethods) {


	RETURN_MEMBER(this_ptr, "_methods");

}

/**
 * Sets a hostname restriction to the route
 *
 *<code>
 * $route->setHostname('localhost');
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, setHostname) {

	zval *hostname;

	zephir_fetch_params(0, 1, 0, &hostname);



	zephir_update_property_this(this_ptr, SL("_hostname"), hostname TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the hostname restriction if any
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getHostname) {


	RETURN_MEMBER(this_ptr, "_hostname");

}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string name
 * @param callable converter
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, convert) {

	zval *name, *converter;

	zephir_fetch_params(0, 2, 0, &name, &converter);



	zephir_update_property_array(this_ptr, SL("_converters"), name, converter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the router converter
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getConverters) {


	RETURN_MEMBER(this_ptr, "_converters");

}

