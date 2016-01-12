#include "Vector2D.h"
#include "Matrix2D.h"
#include "Board.h"
#include "Level.h"
#include "ConfigImage.h"
#include "MapImage.h"
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"
#include "NullArrayException.h"
#include "WrongValueException.h"
#include "WrongSizeException.h"

#define BOOST_TEST_MODULE EditorTM test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_Vector2D);
	BOOST_AUTO_TEST_CASE(constructors_test){
		Vector2D v_def;
		BOOST_CHECK_EQUAL(v_def.getX(), 0);
		BOOST_CHECK_EQUAL(v_def.getY(), 0);
		BOOST_CHECK_EQUAL(v_def[2], 1);

		Vector2D v_1param(21);
		BOOST_CHECK_EQUAL(v_1param.getX(), 21);
		BOOST_CHECK_EQUAL(v_1param.getY(), 0);
		BOOST_CHECK_EQUAL(v_1param[2], 1);

		Vector2D v1_2param(-11, 22);
		BOOST_CHECK_EQUAL(v1_2param.getX(), -11);
		BOOST_CHECK_EQUAL(v1_2param.getY(), 22);
		BOOST_CHECK_EQUAL(v1_2param[2], 1);

		Vector2D v2_copy(-11, 22);
		v1_2param.setXY(1, 1);
		BOOST_CHECK_EQUAL(v2_copy.getX(), -11);
		BOOST_CHECK_EQUAL(v2_copy.getY(), 22);
		BOOST_CHECK_EQUAL(v2_copy[2], 1);
	}

	BOOST_AUTO_TEST_CASE(getters_test){
		Vector2D v1(2, 3);
		BOOST_CHECK_EQUAL(v1.getX(), 2);
		BOOST_CHECK_EQUAL(v1.getY(), 3);

		float x, y;
		v1.getXY(x, y);
		BOOST_CHECK_EQUAL(x, 2);
		BOOST_CHECK_EQUAL(y, 3);

		BOOST_CHECK_EQUAL(v1.getX(), v1[0]);
		BOOST_CHECK_EQUAL(v1.getY(), v1[1]);
		BOOST_CHECK_EQUAL(v1[2], 1);
	}


	BOOST_AUTO_TEST_CASE(setters_test){
		Vector2D v1;
		v1.setX(2);
		v1.setY(5);
		BOOST_CHECK_EQUAL(v1[0], 2);
		BOOST_CHECK_EQUAL(v1[1], 5);
		BOOST_CHECK_EQUAL(v1[2], 1);

		v1.setXY(20.5, 11);
		BOOST_CHECK_EQUAL(v1[0], 20.5);
		BOOST_CHECK_EQUAL(v1[1], 11);
		BOOST_CHECK_EQUAL(v1[2], 1);

		v1[0] = 25;
		BOOST_CHECK_EQUAL(v1[0], 25);
		BOOST_CHECK_EQUAL(v1[1], 11);
		BOOST_CHECK_EQUAL(v1[2], 1);

		v1[1] = 26;
		BOOST_CHECK_EQUAL(v1[0], 25);
		BOOST_CHECK_EQUAL(v1[1], 26);
		BOOST_CHECK_EQUAL(v1[2], 1);

		v1[2] = 12;
		BOOST_CHECK_EQUAL(v1[0], 25);
		BOOST_CHECK_EQUAL(v1[1], 26);
		BOOST_CHECK_EQUAL(v1[2], 12);

		v1.resetValues();
		BOOST_CHECK_EQUAL(v1[0], 0);
		BOOST_CHECK_EQUAL(v1[1], 0);
		BOOST_CHECK_EQUAL(v1[2], 1);
	}

	BOOST_AUTO_TEST_CASE(operators_test){
		Vector2D v1(2, 3);
		Vector2D v2(21, 33);
		v1 += v2;
		BOOST_CHECK_EQUAL(v1.getX(), 23);
		BOOST_CHECK_EQUAL(v1.getY(), 36);
		BOOST_CHECK_EQUAL(v1[2], 1);

		v2 += 1;
		BOOST_CHECK_EQUAL(v1.getX(), 23);
		BOOST_CHECK_EQUAL(v1.getY(), 36);
		BOOST_CHECK_EQUAL(v1[2], 1);
		BOOST_CHECK_EQUAL(v2.getX(), 22);
		BOOST_CHECK_EQUAL(v2.getY(), 34);
		BOOST_CHECK_EQUAL(v2[2], 1);

		Vector2D v3;
		v3 = v1 + v2;
		v1 += 2;
		v2 += 3;
		BOOST_CHECK_EQUAL(v3.getX(), 45);
		BOOST_CHECK_EQUAL(v3.getY(), 70);

		v3 = v1 + 5;
		BOOST_CHECK_EQUAL(v3.getX(), 30);
		BOOST_CHECK_EQUAL(v3.getY(), 43);
		BOOST_CHECK_EQUAL(v3[2], 1);

		Vector2D v4;
		v4 = v3;
		v3 -= 2;
		BOOST_CHECK_EQUAL(v4.getX(), 30);
		BOOST_CHECK_EQUAL(v4.getY(), 43);
		BOOST_CHECK_EQUAL(v4[2], 1);
		BOOST_CHECK_EQUAL(v3.getX(), 28);
		BOOST_CHECK_EQUAL(v3.getY(), 41);
		BOOST_CHECK_EQUAL(v3[2], 1);


		v4 = 3;
		BOOST_CHECK_EQUAL(v4.getX(), 3);
		BOOST_CHECK_EQUAL(v4.getY(), 3);
		BOOST_CHECK_EQUAL(v4[2], 1);
		v4[1] = 1;

		v3 -= v4;
		BOOST_CHECK_EQUAL(v3.getX(), 25);
		BOOST_CHECK_EQUAL(v3.getY(), 40);
		BOOST_CHECK_EQUAL(v3[2], 1);

		v3 = v4 - 1;
		v4 -= 2;
		BOOST_CHECK_EQUAL(v3.getX(), 2);
		BOOST_CHECK_EQUAL(v3.getY(), 0);
		BOOST_CHECK_EQUAL(v3[2], 1);

		v1.setXY(-5, 2);
		v3 = v4 - v1;
		v4 -= 1;
		v1 += 20;
		BOOST_CHECK_EQUAL(v3.getX(), 6);
		BOOST_CHECK_EQUAL(v3.getY(), -3);
		BOOST_CHECK_EQUAL(v3[2], 1);

		BOOST_CHECK_THROW(v3[-1], NegativeIndexException);
		BOOST_CHECK_THROW(v3[5], OutOfRangeIndexException);
	}

	BOOST_AUTO_TEST_CASE(functional_test){
		Vector2D v1(0, 0);
		v1.fit(0, 0, 2, 4, 0, 0, 100, 100);
		BOOST_CHECK_EQUAL(v1.getX(), 0);
		BOOST_CHECK_EQUAL(v1.getY(), 100);

		Vector2D v2(0, 0);
		v2.fit(2, 0, 0, 4, 0, 0, 100, 100);
		BOOST_CHECK_EQUAL(v2.getX(), 100);
		BOOST_CHECK_EQUAL(v2.getY(), 100);
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(test_Matrix2D);
	BOOST_AUTO_TEST_CASE(constructors_test){
		Matrix2D mat1;
		BOOST_CHECK_EQUAL(mat1(0, 0), 0);	BOOST_CHECK_EQUAL(mat1(0, 1), 0);	BOOST_CHECK_EQUAL(mat1(0, 2), 0);
		BOOST_CHECK_EQUAL(mat1(1, 0), 0);	BOOST_CHECK_EQUAL(mat1(1, 1), 0);	BOOST_CHECK_EQUAL(mat1(1, 2), 0);
		BOOST_CHECK_EQUAL(mat1(2, 0), 0);	BOOST_CHECK_EQUAL(mat1(2, 1), 0);	BOOST_CHECK_EQUAL(mat1(2, 2), 1);

		mat1 = Matrix2D::getScale(3, 2);
		Matrix2D mat2(mat1);
		mat1(1, 1) = 5;
		BOOST_CHECK_EQUAL(mat2(0, 0), 3);	BOOST_CHECK_EQUAL(mat2(0, 1), 0);	BOOST_CHECK_EQUAL(mat2(0, 2), 0);
		BOOST_CHECK_EQUAL(mat2(1, 0), 0);	BOOST_CHECK_EQUAL(mat2(1, 1), 2);	BOOST_CHECK_EQUAL(mat2(1, 2), 0);
		BOOST_CHECK_EQUAL(mat2(2, 0), 0);	BOOST_CHECK_EQUAL(mat2(2, 1), 0);	BOOST_CHECK_EQUAL(mat2(2, 2), 1);
	}

	BOOST_AUTO_TEST_CASE(operations_test){
		Matrix2D mat1(Matrix2D::getScale(5, 2));
		BOOST_CHECK_EQUAL(mat1(0, 0), 5);	BOOST_CHECK_EQUAL(mat1(0, 1), 0);	BOOST_CHECK_EQUAL(mat1(0, 2), 0);
		BOOST_CHECK_EQUAL(mat1(1, 0), 0);	BOOST_CHECK_EQUAL(mat1(1, 1), 2);	BOOST_CHECK_EQUAL(mat1(1, 2), 0);
		BOOST_CHECK_EQUAL(mat1(2, 0), 0);	BOOST_CHECK_EQUAL(mat1(2, 1), 0);	BOOST_CHECK_EQUAL(mat1(2, 2), 1);

		Matrix2D mat2(Matrix2D::getTranslate(5, 2));
		BOOST_CHECK_EQUAL(mat2(0, 0), 1);	BOOST_CHECK_EQUAL(mat2(0, 1), 0);	BOOST_CHECK_EQUAL(mat2(0, 2), 5);
		BOOST_CHECK_EQUAL(mat2(1, 0), 0);	BOOST_CHECK_EQUAL(mat2(1, 1), 1);	BOOST_CHECK_EQUAL(mat2(1, 2), 2);
		BOOST_CHECK_EQUAL(mat2(2, 0), 0);	BOOST_CHECK_EQUAL(mat2(2, 1), 0);	BOOST_CHECK_EQUAL(mat2(2, 2), 1);

		Vector2D vec1(2, 1);
		vec1 = mat2*vec1;
		BOOST_CHECK_EQUAL(vec1[0], 7);
		BOOST_CHECK_EQUAL(vec1[1], 3);
		BOOST_CHECK_EQUAL(vec1[2], 1);
		vec1 = mat1*vec1;
		BOOST_CHECK_EQUAL(vec1[0], 35);
		BOOST_CHECK_EQUAL(vec1[1], 6);
		BOOST_CHECK_EQUAL(vec1[2], 1);

		Matrix2D mat3(Matrix2D::getBasic());
		mat3.scale(5, 2).translate(5, 2);

		Vector2D vec2(2, 1);
		vec2 = mat3 * vec2;
		BOOST_CHECK_EQUAL(vec2[0], 35);
		BOOST_CHECK_EQUAL(vec2[1], 6);
		BOOST_CHECK_EQUAL(vec2[2], 1);
	}

	BOOST_AUTO_TEST_CASE(operators_test){
		Matrix2D mat1;
		BOOST_CHECK_THROW(mat1(-1, 0), NegativeIndexException);
		BOOST_CHECK_THROW(mat1(0, -1), NegativeIndexException);
		BOOST_CHECK_THROW(mat1(3, 0), OutOfRangeIndexException);
		BOOST_CHECK_THROW(mat1(0, 3), OutOfRangeIndexException);

		Matrix2D mat2(Matrix2D::getTranslate(1, 1));
		mat2 = mat1;
		mat1(2, 2) = 4.2f;
		BOOST_CHECK_EQUAL(mat2(0, 0), 0);	BOOST_CHECK_EQUAL(mat2(0, 1), 0);	BOOST_CHECK_EQUAL(mat2(0, 2), 0);
		BOOST_CHECK_EQUAL(mat2(1, 0), 0);	BOOST_CHECK_EQUAL(mat2(1, 1), 0);	BOOST_CHECK_EQUAL(mat2(1, 2), 0);
		BOOST_CHECK_EQUAL(mat2(2, 0), 0);	BOOST_CHECK_EQUAL(mat2(2, 1), 0);	BOOST_CHECK_EQUAL(mat2(2, 2), 1);
		Matrix2D mat3 = Matrix2D::getTranslate(2, 3) * 2;
		BOOST_CHECK_EQUAL(mat3(0, 0), 2);	BOOST_CHECK_EQUAL(mat3(0, 1), 0);	BOOST_CHECK_EQUAL(mat3(0, 2), 4);
		BOOST_CHECK_EQUAL(mat3(1, 0), 0);	BOOST_CHECK_EQUAL(mat3(1, 1), 2);	BOOST_CHECK_EQUAL(mat3(1, 2), 6);
		BOOST_CHECK_EQUAL(mat3(2, 0), 0);	BOOST_CHECK_EQUAL(mat3(2, 1), 0);	BOOST_CHECK_EQUAL(mat3(2, 2), 2);

		Matrix2D mat4 = mat3*Matrix2D::getScale(0.5, 2);
		BOOST_CHECK_EQUAL(mat3(0, 0), 2);	BOOST_CHECK_EQUAL(mat3(0, 1), 0);	BOOST_CHECK_EQUAL(mat3(0, 2), 4);
		BOOST_CHECK_EQUAL(mat3(1, 0), 0);	BOOST_CHECK_EQUAL(mat3(1, 1), 2);	BOOST_CHECK_EQUAL(mat3(1, 2), 6);
		BOOST_CHECK_EQUAL(mat3(2, 0), 0);	BOOST_CHECK_EQUAL(mat3(2, 1), 0);	BOOST_CHECK_EQUAL(mat3(2, 2), 2);
		BOOST_CHECK_EQUAL(mat4(0, 0), 1);	BOOST_CHECK_EQUAL(mat4(0, 1), 0);	BOOST_CHECK_EQUAL(mat4(0, 2), 4);
		BOOST_CHECK_EQUAL(mat4(1, 0), 0);	BOOST_CHECK_EQUAL(mat4(1, 1), 4);	BOOST_CHECK_EQUAL(mat4(1, 2), 6);
		BOOST_CHECK_EQUAL(mat4(2, 0), 0);	BOOST_CHECK_EQUAL(mat4(2, 1), 0);	BOOST_CHECK_EQUAL(mat4(2, 2), 2);

		Matrix2D mat5 = mat4 + 2;
		BOOST_CHECK_EQUAL(mat4(0, 0), 1);	BOOST_CHECK_EQUAL(mat4(0, 1), 0);	BOOST_CHECK_EQUAL(mat4(0, 2), 4);
		BOOST_CHECK_EQUAL(mat4(1, 0), 0);	BOOST_CHECK_EQUAL(mat4(1, 1), 4);	BOOST_CHECK_EQUAL(mat4(1, 2), 6);
		BOOST_CHECK_EQUAL(mat4(2, 0), 0);	BOOST_CHECK_EQUAL(mat4(2, 1), 0);	BOOST_CHECK_EQUAL(mat4(2, 2), 2);
		BOOST_CHECK_EQUAL(mat5(0, 0), 3);	BOOST_CHECK_EQUAL(mat5(0, 1), 2);	BOOST_CHECK_EQUAL(mat5(0, 2), 6);
		BOOST_CHECK_EQUAL(mat5(1, 0), 2);	BOOST_CHECK_EQUAL(mat5(1, 1), 6);	BOOST_CHECK_EQUAL(mat5(1, 2), 8);
		BOOST_CHECK_EQUAL(mat5(2, 0), 2);	BOOST_CHECK_EQUAL(mat5(2, 1), 2);	BOOST_CHECK_EQUAL(mat5(2, 2), 4);

		Matrix2D mat6 = mat5 + Matrix2D::getTranslate(2, 3);
		BOOST_CHECK_EQUAL(mat5(0, 0), 3);	BOOST_CHECK_EQUAL(mat5(0, 1), 2);	BOOST_CHECK_EQUAL(mat5(0, 2), 6);
		BOOST_CHECK_EQUAL(mat5(1, 0), 2);	BOOST_CHECK_EQUAL(mat5(1, 1), 6);	BOOST_CHECK_EQUAL(mat5(1, 2), 8);
		BOOST_CHECK_EQUAL(mat5(2, 0), 2);	BOOST_CHECK_EQUAL(mat5(2, 1), 2);	BOOST_CHECK_EQUAL(mat5(2, 2), 4);
		BOOST_CHECK_EQUAL(mat6(0, 0), 4);	BOOST_CHECK_EQUAL(mat6(0, 1), 2);	BOOST_CHECK_EQUAL(mat6(0, 2), 8);
		BOOST_CHECK_EQUAL(mat6(1, 0), 2);	BOOST_CHECK_EQUAL(mat6(1, 1), 7);	BOOST_CHECK_EQUAL(mat6(1, 2), 11);
		BOOST_CHECK_EQUAL(mat6(2, 0), 2);	BOOST_CHECK_EQUAL(mat6(2, 1), 2);	BOOST_CHECK_EQUAL(mat6(2, 2), 5);
		Matrix2D mat7;
		mat7 += 1;
		BOOST_CHECK_EQUAL(mat7(0, 0), 1);	BOOST_CHECK_EQUAL(mat7(0, 1), 1);	BOOST_CHECK_EQUAL(mat7(0, 2), 1);
		BOOST_CHECK_EQUAL(mat7(1, 0), 1);	BOOST_CHECK_EQUAL(mat7(1, 1), 1);	BOOST_CHECK_EQUAL(mat7(1, 2), 1);
		BOOST_CHECK_EQUAL(mat7(2, 0), 1);	BOOST_CHECK_EQUAL(mat7(2, 1), 1);	BOOST_CHECK_EQUAL(mat7(2, 2), 2);

		mat7 += mat5;
		BOOST_CHECK_EQUAL(mat7(0, 0), 4);	BOOST_CHECK_EQUAL(mat7(0, 1), 3);	BOOST_CHECK_EQUAL(mat7(0, 2), 7);
		BOOST_CHECK_EQUAL(mat7(1, 0), 3);	BOOST_CHECK_EQUAL(mat7(1, 1), 7);	BOOST_CHECK_EQUAL(mat7(1, 2), 9);
		BOOST_CHECK_EQUAL(mat7(2, 0), 3);	BOOST_CHECK_EQUAL(mat7(2, 1), 3);	BOOST_CHECK_EQUAL(mat7(2, 2), 6);
		mat3 *= Matrix2D::getScale(0.5, 2);
		BOOST_CHECK_EQUAL(mat3(0, 0), 1);	BOOST_CHECK_EQUAL(mat3(0, 1), 0);	BOOST_CHECK_EQUAL(mat3(0, 2), 4);
		BOOST_CHECK_EQUAL(mat3(1, 0), 0);	BOOST_CHECK_EQUAL(mat3(1, 1), 4);	BOOST_CHECK_EQUAL(mat3(1, 2), 6);
		BOOST_CHECK_EQUAL(mat3(2, 0), 0);	BOOST_CHECK_EQUAL(mat3(2, 1), 0);	BOOST_CHECK_EQUAL(mat3(2, 2), 2);
	}
BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(test_Board);
	BOOST_AUTO_TEST_CASE(constructors_test){
		Board b1;
		BOOST_CHECK_THROW(b1(0, 0), NullArrayException);

		BOOST_CHECK_EQUAL(b1.getHeight(), 0);
		BOOST_CHECK_EQUAL(b1.getWidth(), 0);

		Board b2(10, 15);
		BOOST_CHECK_EQUAL(b2(2, 5), 0);
		BOOST_CHECK_EQUAL(b2(8, 1), 0);
		BOOST_CHECK_EQUAL(b2.getHeight(), 15);
		BOOST_CHECK_EQUAL(b2.getWidth(), 10);
		
		Board b3(b2);
		b2(1, 1, 3);
		b1.resize(5, 5);
		BOOST_CHECK_EQUAL(b3(1, 1), 0);
		BOOST_CHECK_EQUAL(b3(8, 1), 0);
		BOOST_CHECK_EQUAL(b3.getHeight(), 15);
		BOOST_CHECK_EQUAL(b3.getWidth(), 10);
		BOOST_CHECK_THROW(Board b4(2, 3), WrongSizeException);
		BOOST_CHECK_THROW(Board b4(3, 2), WrongSizeException);
		BOOST_CHECK_THROW(Board b4(31, 3), WrongSizeException);
		BOOST_CHECK_THROW(Board b4(3, 31), WrongSizeException);
	}

	BOOST_AUTO_TEST_CASE(opearators_test){
		Board b1(10, 12);
		Board b2;
		b2 = b1;
		b2.fillWith(-1);
		b2(4, 5, 3);
		b1.resize(5, 3);
		BOOST_CHECK_EQUAL(b2.getHeight(), 12);
		BOOST_CHECK_EQUAL(b2.getWidth(), 10);
		BOOST_CHECK_EQUAL(b2(2, 3), -1);
		BOOST_CHECK_EQUAL(b2(4, 5), 3);
		BOOST_CHECK_THROW(b2(10, 10), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b2(5, 12), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b2(-1, 10), NegativeIndexException);
		BOOST_CHECK_THROW(b2(5, -1), NegativeIndexException);
		BOOST_CHECK_THROW(b2(10, 10, 0), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b2(5, 12, 0), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b2(-1, 10, 0), NegativeIndexException);
		BOOST_CHECK_THROW(b2(5, -1, 0), NegativeIndexException);
		BOOST_CHECK_THROW(b2(2, 3, 6), WrongValueException);
		BOOST_CHECK_THROW(b2(4, 5, -2), WrongValueException);
		Board b3;
		BOOST_CHECK_THROW(b3(1, 1), NullArrayException);
		BOOST_CHECK_THROW(b3(1, 1, 0), NullArrayException);
		Board b4(0, 0);
		BOOST_CHECK_EQUAL(b4.isValid(), false);
	}

	BOOST_AUTO_TEST_CASE(getters_test){
		Board b1(10, 13);
		BOOST_CHECK_EQUAL(b1.getHeight(), 13);
		BOOST_CHECK_EQUAL(b1.getWidth(), 10);
		BOOST_CHECK_EQUAL(b1.getValue(2, 2), 0);

		Board b2;
		BOOST_CHECK_THROW(b2.getValue(2, 2), NullArrayException);
		BOOST_CHECK_THROW(b1.getValue(-1, 2), NegativeIndexException);
		BOOST_CHECK_THROW(b1.getValue(2, -1), NegativeIndexException);
		BOOST_CHECK_THROW(b1.getValue(11, 2), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b1.getValue(2, 13), OutOfRangeIndexException);
	}

	BOOST_AUTO_TEST_CASE(setters_test){
		Board b1(10, 10);
		BOOST_CHECK_THROW(b1.fillWith(-2), WrongValueException);
		BOOST_CHECK_THROW(b1.fillWith(6), WrongValueException);
		b1.fillWith(2);
		BOOST_CHECK_EQUAL(b1(2, 2), 2);
		BOOST_CHECK_EQUAL(b1(4, 6), 2);
		Board b2;
		BOOST_CHECK_THROW(b2.fillWith(3), NullArrayException);

		BOOST_CHECK_THROW(b2.setValue(0, 0, 2), NullArrayException);
		b2.resize(15, 10);
		BOOST_CHECK_EQUAL(b2.setValue(2, 3, 2), 0);
		BOOST_CHECK_EQUAL(b2(2, 3), 2);
		BOOST_CHECK_THROW(b2.setValue(1, 1, 6), WrongValueException);
		BOOST_CHECK_THROW(b2.setValue(1, 1, -2), WrongValueException);
		BOOST_CHECK_THROW(b2.setValue(-1, 1, 2), NegativeIndexException);
		BOOST_CHECK_THROW(b2.setValue(1, -1, 2), NegativeIndexException);
		BOOST_CHECK_THROW(b2.setValue(15, 1, 2), OutOfRangeIndexException);
		BOOST_CHECK_THROW(b2.setValue(1, 10, 2), OutOfRangeIndexException);
	}

	BOOST_AUTO_TEST_CASE(resize_test){
		Board b1(10, 15);
		b1.fillWith(3);
		b1.resize(20, 12);
		BOOST_CHECK_EQUAL(b1(2, 1), 3);
		BOOST_CHECK_EQUAL(b1(19, 1), 0);
		BOOST_CHECK_EQUAL(b1.getWidth(), 20);
		BOOST_CHECK_EQUAL(b1.getHeight(), 12);
		BOOST_CHECK_EQUAL(b1.isValid(), true);
		b1.resize(0, 0);
		BOOST_CHECK_EQUAL(b1.getWidth(), 0);
		BOOST_CHECK_EQUAL(b1.getHeight(), 0);
		BOOST_CHECK_EQUAL(b1.isValid(), false);
		Board b2;
		BOOST_CHECK_EQUAL(b2.isValid(), false);
		BOOST_CHECK_THROW(b2.resize(2, 3), WrongSizeException);
		BOOST_CHECK_THROW(b2.resize(3, 2), WrongSizeException);
		BOOST_CHECK_THROW(b2.resize(31, 3), WrongSizeException);
		BOOST_CHECK_THROW(b2.resize(3, 31), WrongSizeException);

	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(test_ConfigImage);
	BOOST_AUTO_TEST_CASE(ratio_test){
		ConfigImage cfgim(100, 150);
		BOOST_CHECK_EQUAL(cfgim.getScaleX(), 1);
		BOOST_CHECK_EQUAL(cfgim.getScaleY(), 1.5);
		cfgim.setImgSize(150, 50);
		cfgim.calculateRatio();
		BOOST_CHECK_EQUAL(cfgim.getScaleX(), 3);
		BOOST_CHECK_EQUAL(cfgim.getScaleY(), 1);
		cfgim.setImgSize(150, 0);
		cfgim.calculateRatio();
		BOOST_CHECK_EQUAL(cfgim.getScaleX(), 0);
		BOOST_CHECK_EQUAL(cfgim.getScaleY(), 0);
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(test_Level);
	BOOST_AUTO_TEST_CASE(difficulty_test){
		Level lvl;
		BOOST_CHECK_THROW(lvl.setDifficulty(2), WrongValueException);
		BOOST_CHECK_THROW(lvl.setDifficulty(8), WrongValueException);
		BOOST_CHECK_THROW(lvl.setDifficulty(-4), WrongValueException);
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(test_MapImage);
BOOST_AUTO_TEST_CASE(adjusting_test){
	Level lvl1(5, 6);
	MapImage mi(lvl1);
	float x0, y0, x1, y1;
	mi.getCoords(x0, y0, x1, y1);
	BOOST_CHECK_EQUAL(x0, -2.5);
	BOOST_CHECK_EQUAL(y0, -3);
	BOOST_CHECK_EQUAL(x1, 2.5);
	BOOST_CHECK_EQUAL(x1, 3);
}
BOOST_AUTO_TEST_SUITE_END();
