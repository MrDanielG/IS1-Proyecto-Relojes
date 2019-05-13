-- phpMyAdmin SQL Dump
-- version 4.8.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 10-05-2019 a las 22:20:55
-- Versión del servidor: 10.1.34-MariaDB
-- Versión de PHP: 7.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `db_relojes`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `contacto`
--

CREATE TABLE `contacto` (
  `id_contacto` int(11) NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `paterno` varchar(45) NOT NULL,
  `materno` varchar(45) NOT NULL,
  `telefono` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `contacto`
--

INSERT INTO `contacto` (`id_contacto`, `nombre`, `paterno`, `materno`, `telefono`) VALUES
(1, 'Daniel', 'Garnica', 'Sanchez', '4921417232'),
(3, 'Hugo', 'Berra', 'Salazar', '123654321'),
(4, 'Jose', 'Cortez', 'Martinez', '123456789'),
(5, 'Chuy', 'Sanchez', 'Hernandez', '7865465456'),
(7, 'Sergio', 'Martinez', 'Fernandez', '456789123'),
(8, 'Antonio', 'Crtez', 'Hernandez', '1597536542'),
(24, 'Martin', 'Coba', 'Pulido', '12345753');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `direccion`
--

CREATE TABLE `direccion` (
  `id_direccion` int(11) NOT NULL,
  `calle` varchar(45) NOT NULL,
  `colonia` varchar(45) NOT NULL,
  `codigo_postal` int(11) NOT NULL,
  `num_exterior` varchar(45) DEFAULT NULL,
  `num_interior` varchar(45) NOT NULL,
  `municipio` varchar(45) NOT NULL,
  `estado` varchar(45) NOT NULL,
  `id_contacto` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `direccion`
--

INSERT INTO `direccion` (`id_direccion`, `calle`, `colonia`, `codigo_postal`, `num_exterior`, `num_interior`, `municipio`, `estado`, `id_contacto`) VALUES
(1, '14 sur', 'Los Heroes', 72040, '72', '6', 'Puebla', 'Puebla', 1);

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `infopedido`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `infopedido` (
`id_pedido` int(11)
,`fecha_entrega` date
,`tipo_pago` varchar(45)
,`id_contacto` int(11)
,`nombre` varchar(45)
,`paterno` varchar(45)
,`cantidad` int(11)
,`marca` varchar(45)
,`modelo` varchar(45)
,`precio` float
,`Total` double
);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `linea_pedido`
--

CREATE TABLE `linea_pedido` (
  `id_producto` int(11) NOT NULL,
  `id_pedido` int(11) NOT NULL,
  `cantidad` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `linea_pedido`
--

INSERT INTO `linea_pedido` (`id_producto`, `id_pedido`, `cantidad`) VALUES
(1, 1, 3),
(1, 2, 3),
(1, 4, 7),
(1, 5, 8),
(1, 9, 2),
(1, 10, 5),
(1, 12, 2),
(1, 18, 3),
(1, 21, 1),
(3, 3, 5),
(3, 4, 1),
(3, 5, 2),
(3, 6, 6),
(3, 8, 6),
(3, 14, 2),
(3, 15, 4),
(3, 16, 3),
(3, 19, 3),
(3, 22, 4),
(4, 6, 3),
(4, 8, 7),
(4, 11, 6),
(4, 13, 12),
(4, 20, 2),
(5, 7, 2),
(5, 17, 8),
(5, 20, 9);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pedido`
--

CREATE TABLE `pedido` (
  `id_pedido` int(11) NOT NULL,
  `fecha_entrega` date NOT NULL,
  `tipo_pago` varchar(45) NOT NULL,
  `contacto_id_contacto` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `pedido`
--

INSERT INTO `pedido` (`id_pedido`, `fecha_entrega`, `tipo_pago`, `contacto_id_contacto`) VALUES
(1, '0000-00-00', 'Efectivo', 3),
(2, '0000-00-00', 'Efectivo', 3),
(3, '2019-05-09', 'Efectivo', 5),
(4, '2019-05-09', 'Efectivo', 5),
(5, '2019-05-09', 'Tarjeta', 24),
(6, '2019-05-09', 'Tarjeta', 7),
(7, '2019-05-10', 'Tarjeta', 7),
(8, '2019-05-10', 'Efectivo', 1),
(9, '2019-05-10', 'Efectivo', 1),
(10, '2019-05-10', 'Efectivo', 24),
(11, '2019-05-10', 'Tarjeta', 7),
(12, '2019-05-10', 'Efectivo', 1),
(13, '2019-05-10', 'Tarjeta', 8),
(14, '2019-05-10', 'Tarjeta', 3),
(15, '2019-05-10', 'Tarjeta', 4),
(16, '2019-05-10', 'Tarjeta', 1),
(17, '2019-05-10', 'Efectivo', 3),
(18, '2019-05-10', 'Efectivo', 1),
(19, '2019-05-10', 'Efectivo', 5),
(20, '2019-05-10', 'Efectivo', 7),
(21, '2019-05-10', 'Efectivo', 1),
(22, '2019-05-10', 'Efectivo', 5);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `id_producto` int(11) NOT NULL,
  `marca` varchar(45) NOT NULL,
  `modelo` varchar(45) NOT NULL,
  `precio` float NOT NULL,
  `descripcion` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `producto`
--

INSERT INTO `producto` (`id_producto`, `marca`, `modelo`, `precio`, `descripcion`) VALUES
(1, 'Zelco', 'Zn-02', 12, 'Pieza Grande'),
(3, 'Zelco', 'Zn-03', 13, 'Pieza Chica'),
(4, 'Rolex', 'BigShut', 30000, 'Muy Caro'),
(5, 'Casio', 'C-05', 250, 'Reloj con Caluladora');

-- --------------------------------------------------------

--
-- Estructura para la vista `infopedido`
--
DROP TABLE IF EXISTS `infopedido`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `infopedido`  AS  select `ped`.`id_pedido` AS `id_pedido`,`ped`.`fecha_entrega` AS `fecha_entrega`,`ped`.`tipo_pago` AS `tipo_pago`,`con`.`id_contacto` AS `id_contacto`,`con`.`nombre` AS `nombre`,`con`.`paterno` AS `paterno`,`lp`.`cantidad` AS `cantidad`,`prod`.`marca` AS `marca`,`prod`.`modelo` AS `modelo`,`prod`.`precio` AS `precio`,sum((`lp`.`cantidad` * `prod`.`precio`)) AS `Total` from (((`contacto` `con` join `pedido` `ped` on((`con`.`id_contacto` = `ped`.`contacto_id_contacto`))) join `linea_pedido` `lp` on((`ped`.`id_pedido` = `lp`.`id_pedido`))) join `producto` `prod` on((`lp`.`id_producto` = `prod`.`id_producto`))) group by `ped`.`id_pedido` ;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `contacto`
--
ALTER TABLE `contacto`
  ADD PRIMARY KEY (`id_contacto`);

--
-- Indices de la tabla `direccion`
--
ALTER TABLE `direccion`
  ADD PRIMARY KEY (`id_direccion`),
  ADD KEY `id_contacto` (`id_contacto`);

--
-- Indices de la tabla `linea_pedido`
--
ALTER TABLE `linea_pedido`
  ADD PRIMARY KEY (`id_producto`,`id_pedido`),
  ADD KEY `id_pedido` (`id_pedido`);

--
-- Indices de la tabla `pedido`
--
ALTER TABLE `pedido`
  ADD PRIMARY KEY (`id_pedido`),
  ADD KEY `contacto_id_contacto` (`contacto_id_contacto`);

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`id_producto`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `contacto`
--
ALTER TABLE `contacto`
  MODIFY `id_contacto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- AUTO_INCREMENT de la tabla `direccion`
--
ALTER TABLE `direccion`
  MODIFY `id_direccion` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT de la tabla `pedido`
--
ALTER TABLE `pedido`
  MODIFY `id_pedido` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT de la tabla `producto`
--
ALTER TABLE `producto`
  MODIFY `id_producto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `direccion`
--
ALTER TABLE `direccion`
  ADD CONSTRAINT `direccion_ibfk_1` FOREIGN KEY (`id_contacto`) REFERENCES `contacto` (`id_contacto`);

--
-- Filtros para la tabla `linea_pedido`
--
ALTER TABLE `linea_pedido`
  ADD CONSTRAINT `linea_pedido_ibfk_1` FOREIGN KEY (`id_producto`) REFERENCES `producto` (`id_producto`),
  ADD CONSTRAINT `linea_pedido_ibfk_2` FOREIGN KEY (`id_pedido`) REFERENCES `pedido` (`id_pedido`);

--
-- Filtros para la tabla `pedido`
--
ALTER TABLE `pedido`
  ADD CONSTRAINT `pedido_ibfk_1` FOREIGN KEY (`contacto_id_contacto`) REFERENCES `contacto` (`id_contacto`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
