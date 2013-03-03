-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 26, 2012 at 05:12 PM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `java`
--

-- --------------------------------------------------------

--
-- Table structure for table `data_t`
--

CREATE TABLE IF NOT EXISTS `data_t` (
  `title` varchar(10000) NOT NULL,
  `file` varchar(10000) NOT NULL,
  `abouts` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `forum_ans`
--

CREATE TABLE IF NOT EXISTS `forum_ans` (
  `tittle` varchar(10000) NOT NULL,
  `review` varchar(30000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `forum_ans`
--

INSERT INTO `forum_ans` (`tittle`, `review`, `goal`, `student_id`) VALUES
('Basic Addition', 'can you please 2 +2 1', 'Fundamental 1 digit Addition', 1);

-- --------------------------------------------------------

--
-- Table structure for table `forum_t`
--

CREATE TABLE IF NOT EXISTS `forum_t` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `tittle` varchar(10000) NOT NULL,
  `instructions` varchar(10000) NOT NULL,
  `Goal` varchar(30) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `forum_t`
--

INSERT INTO `forum_t` (`id`, `tittle`, `instructions`, `Goal`) VALUES
(13, 'Basic Addition', 'Post your doubts related to the first lecture here ! :D', 'Fundamental 1 digit Addition'),
(14, 'Forum', 'you ca post your doubts her e !\n ', 'demo'),
(15, 'demo', 'asd', 'demo');

-- --------------------------------------------------------

--
-- Table structure for table `goal_record_t`
--

CREATE TABLE IF NOT EXISTS `goal_record_t` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `goal` varchar(10000) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=34 ;

--
-- Dumping data for table `goal_record_t`
--

INSERT INTO `goal_record_t` (`id`, `goal`) VALUES
(13, 'Fundamental 1 digit Addition'),
(14, 'demo'),
(15, 'demo'),
(16, 'Fundamental 1 digit Addition'),
(17, 'Fundamental 1 digit Addition'),
(18, 'Fundamental 1 digit Addition'),
(19, 'demo'),
(20, 'demo'),
(21, 'Fundamental 1 digit Addition'),
(22, 'Fundamental 1 digit Addition'),
(23, 'demo'),
(24, 'demo'),
(25, 'demo'),
(26, 'demo'),
(27, 'demo'),
(28, 'Teach Addition'),
(29, 'Teach Addition'),
(30, 'Teach Addition'),
(31, 'demo'),
(32, 'Fundamental 1 digit Addition'),
(33, 'Fundamental 1 digit Addition');

-- --------------------------------------------------------

--
-- Table structure for table `goal_t`
--

CREATE TABLE IF NOT EXISTS `goal_t` (
  `name` varchar(10000) NOT NULL,
  `username` varchar(10000) NOT NULL,
  `starting` varchar(10000) NOT NULL,
  `ending` varchar(10000) NOT NULL,
  `about` varchar(10000) NOT NULL,
  `priority` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `goal_t`
--

INSERT INTO `goal_t` (`name`, `username`, `starting`, `ending`, `about`, `priority`) VALUES
('goal', 'Username', '11-5-07', '11-5-07', 'this is a demo :D ! \n', 'HIGH'),
('goal2', 'Username', '12-0-9', '1-12-11', 'learn java in 2 hours ! ', 'MEDIUM'),
('goal3', 'Username', '1-1-1', '1-2-1', 'learn addition ! ', 'LOW'),
('maths', 'Username', '18-11-2012', '18-11-2012', 'hissar faad hai ! :d', 'HIGH'),
('learning poems', 'ashu1461', '12-5-06', '12-5-06', 'i cannot think of anything really ! \n', 'HIGH'),
('teach mathermatics', 'ashu1461', '11-5-08', '11-5-08', 'let us teach the children how to play with some maths ! \n	', 'HIGH'),
('Fundamental 1 digit Addition', 'ashu1461', '11-9-2012', '11-9-2012', 'Teaching one digit addition to people ! \nAfter this course the student should be able to solve \nsimple one digit addition problems and understand their\nreal life applications and use .', 'HIGH'),
('demo', 'demo', '1--12-1', '1--12-1', 'demo !', 'HIGH'),
('demo', 'demo', '12-5-06', '12-5-06', 'this is a demo for the tool', 'HIGH'),
('Teach Addition', 'singla', '11-5-06', '11-5-06', 'Let us teach the students how to learn basic addition ! \n', 'HIGH');

-- --------------------------------------------------------

--
-- Table structure for table `image_ans`
--

CREATE TABLE IF NOT EXISTS `image_ans` (
  `tittle` varchar(10000) NOT NULL,
  `answer` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `image_ans`
--

INSERT INTO `image_ans` (`tittle`, `answer`, `goal`, `student_id`) VALUES
('question 2', 'I DONT KNOW ANYTHING .. \nSO MAYBE 6', 'Fundamental 1 digit Addition', 1),
('question 5', '9 \nPRETTY MUCH SURE ! \n', 'Fundamental 1 digit Addition', 1);

-- --------------------------------------------------------

--
-- Table structure for table `image_t`
--

CREATE TABLE IF NOT EXISTS `image_t` (
  `pathurl` varchar(10000) NOT NULL,
  `tittle` varchar(10000) NOT NULL,
  `information` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `image_t`
--

INSERT INTO `image_t` (`pathurl`, `tittle`, `information`, `goal`) VALUES
('1.jpg', '1', 'See the image', 'Fundamental 1 digit Addition'),
('2.jpg', '2', 'See the image', 'Fundamental 1 digit Addition'),
('3.jpg', '3', 'See the image', 'Fundamental 1 digit Addition'),
('4.jpg', '4', 'See the image', 'Fundamental 1 digit Addition'),
('5.jpg', '5', 'See the image', 'Fundamental 1 digit Addition'),
('6.jpg', '6', 'See the image', 'Fundamental 1 digit Addition'),
('7.jpg', '7', 'See the image', 'Fundamental 1 digit Addition'),
('8.jpg', '8', 'See the image', 'Fundamental 1 digit Addition'),
('9.jpg', '9', 'See the image', 'Fundamental 1 digit Addition'),
('q2.jpg', 'question 1', 'See the image', 'Fundamental 1 digit Addition'),
('q3.jpg', 'question 2', 'See the image', 'Fundamental 1 digit Addition'),
('q4.jpg', 'question 3', 'See the image', 'Fundamental 1 digit Addition'),
('q8.jpg', 'question 4', 'See the image', 'Fundamental 1 digit Addition'),
('q9.jpg', 'question 5', 'See the image', 'Fundamental 1 digit Addition'),
('1.jpg', 'xzX', 'zx', 'demo'),
('1.jpg', 'HELLO', 'THIS COUNTS TO 1 ', 'Teach Addition'),
('8-1.jpg', 'EIGHT', 'THIS COUNTS TO 1 ', 'Teach Addition');

-- --------------------------------------------------------

--
-- Table structure for table `login_t`
--

CREATE TABLE IF NOT EXISTS `login_t` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(10000) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=47 ;

--
-- Dumping data for table `login_t`
--

INSERT INTO `login_t` (`id`, `username`) VALUES
(25, 'ashu1461'),
(26, 'ashu1461'),
(27, 'demo'),
(28, 'ashu1461'),
(29, 'ashu1461'),
(30, 'ashu1461'),
(31, 'ashu1461'),
(32, 'demo'),
(33, 'demo'),
(34, 'ashu1461'),
(35, 'ashu1461'),
(36, 'ashu1461'),
(37, 'demo'),
(38, 'ashu1461'),
(39, 'demo'),
(40, 'ashu1461'),
(41, 'demo'),
(42, 'singla'),
(43, 'singla'),
(44, 'ashu1461'),
(45, 'singla'),
(46, 'ashu1461');

-- --------------------------------------------------------

--
-- Table structure for table `mcq_ans`
--

CREATE TABLE IF NOT EXISTS `mcq_ans` (
  `tittle` varchar(10000) NOT NULL,
  `ans` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `mcq_ans`
--

INSERT INTO `mcq_ans` (`tittle`, `ans`, `goal`, `student_id`) VALUES
('test', 'adas', 'demo', 1);

-- --------------------------------------------------------

--
-- Table structure for table `mcq_t`
--

CREATE TABLE IF NOT EXISTS `mcq_t` (
  `tittle` varchar(10000) NOT NULL,
  `question` varchar(1000) NOT NULL,
  `ans1` varchar(1000) NOT NULL,
  `ans2` varchar(10000) NOT NULL,
  `ans3` varchar(10000) NOT NULL,
  `ans4` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `mcq_t`
--

INSERT INTO `mcq_t` (`tittle`, `question`, `ans1`, `ans2`, `ans3`, `ans4`, `goal`) VALUES
('test', 'what thef	a', 'asdasd', 'asdasd', 'asdasd', 'adas', 'demo'),
('question 1', 'what does 2 + 2 really mean ???\n\n', 'this is a good question ! ', '444', '44', '4', 'Teach Addition');

-- --------------------------------------------------------

--
-- Table structure for table `notice_t`
--

CREATE TABLE IF NOT EXISTS `notice_t` (
  `tittle` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `notice_t`
--

INSERT INTO `notice_t` (`tittle`, `goal`) VALUES
('asd', 'demo'),
('addition', 'Fundamental 1 digit Addition'),
('j', 'demo'),
('blaa', 'Teach Addition');

-- --------------------------------------------------------

--
-- Table structure for table `proc_t`
--

CREATE TABLE IF NOT EXISTS `proc_t` (
  `goal` varchar(2000) NOT NULL,
  `activity` varchar(2000) NOT NULL,
  `type` varchar(2000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `proc_t`
--

INSERT INTO `proc_t` (`goal`, `activity`, `type`) VALUES
('Fundamental 1 digit Addition', ' Activity 1', 'Forum '),
('Fundamental 1 digit Addition', ' Activity 2', 'MCQ '),
('Fundamental 1 digit Addition', ' Activity 3', 'NoteBook '),
('Fundamental 1 digit Addition', ' Activity 4', 'Q & A '),
('Fundamental 1 digit Addition', ' Activity 5', 'Wiki '),
('Fundamental 1 digit Addition', ' Activity 6', 'Image Galary '),
('Fundamental 1 digit Addition', ' Activity 7', 'Video '),
('Fundamental 1 digit Addition', ' Activity 8', 'Resources '),
('Fundamental 1 digit Addition', ' Activity 9', 'Share Resources '),
('Fundamental 1 digit Addition', ' Activity 10', 'Submit Files '),
('Teach Addition', ' mcq question', 'MCQ ');

-- --------------------------------------------------------

--
-- Table structure for table `que_ans`
--

CREATE TABLE IF NOT EXISTS `que_ans` (
  `tittle` varchar(10000) NOT NULL,
  `answer` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `que_t`
--

CREATE TABLE IF NOT EXISTS `que_t` (
  `tittle` varchar(10000) NOT NULL,
  `question` varchar(10000) NOT NULL,
  `answer` varchar(10000) NOT NULL,
  `marks` int(11) NOT NULL,
  `goal` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `que_t`
--

INSERT INTO `que_t` (`tittle`, `question`, `answer`, `marks`, `goal`) VALUES
('asd', 'da', 'asda', 1, 'asdasd'),
('question 1', 'Does Addition follow ?\nif there are two numbers A and B \nA + B = B+A\nclue : take examples and solve :)', 'yes :)', 7, 'Fundamental 1 digit Addition'),
('question2', 'This question is a further extension of the first question \nIs the following equation true ?\nA+(B+C) = (A+B) +C		', 'yes ! ', 7, 'Fundamental 1 digit Addition'),
('question', 'asda	asd	', 'cxz', 7, 'demo');

-- --------------------------------------------------------

--
-- Table structure for table `student_register`
--

CREATE TABLE IF NOT EXISTS `student_register` (
  `username` varchar(1000) NOT NULL,
  `password` varchar(1000) NOT NULL,
  `email` varchar(1000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student_register`
--

INSERT INTO `student_register` (`username`, `password`, `email`) VALUES
('as', 'a', 'a'),
('a', 'a', 'a'),
('ashu1461', 'ashutosh', 'ashu1@qqdsa');

-- --------------------------------------------------------

--
-- Table structure for table `submit_ans`
--

CREATE TABLE IF NOT EXISTS `submit_ans` (
  `tittle` varchar(10000) NOT NULL,
  `pathurl` varchar(10000) NOT NULL,
  `add_info` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `submit_t`
--

CREATE TABLE IF NOT EXISTS `submit_t` (
  `tittle` varchar(10000) NOT NULL,
  `question` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `submit_t`
--

INSERT INTO `submit_t` (`tittle`, `question`, `goal`) VALUES
('question 1 ', 'Prepare a grid of 10 by 10 numbers and add them by applying the\n addition operation on row operands vs the column opernads ! ', 'Fundamental 1 digit Addition');

-- --------------------------------------------------------

--
-- Table structure for table `teacher_register`
--

CREATE TABLE IF NOT EXISTS `teacher_register` (
  `username` varchar(1000) NOT NULL,
  `password` varchar(1000) NOT NULL,
  `email` varchar(1000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `teacher_register`
--

INSERT INTO `teacher_register` (`username`, `password`, `email`) VALUES
('ashu1461', 'ashu6789', 'as'),
('demo', 'demo', 'demo'),
('singla', '12345', 'singla@singla@.com');

-- --------------------------------------------------------

--
-- Table structure for table `video_ans`
--

CREATE TABLE IF NOT EXISTS `video_ans` (
  `url` varchar(10000) NOT NULL,
  `response` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `video_t`
--

CREATE TABLE IF NOT EXISTS `video_t` (
  `url` varchar(10000) NOT NULL,
  `abouts` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `video_t`
--

INSERT INTO `video_t` (`url`, `abouts`, `goal`) VALUES
('add1.mp4', 'see this video and learn analyse what is being taught ! ', 'Fundamental 1 digit Addition'),
('Addition 2.mp4', '2nd part of the video :) ! ', 'Fundamental 1 digit Addition'),
('Addition 2.mp4', 'asdas', 'demo');

-- --------------------------------------------------------

--
-- Table structure for table `wiki_t`
--

CREATE TABLE IF NOT EXISTS `wiki_t` (
  `tittle` varchar(10000) NOT NULL,
  `url` varchar(10000) NOT NULL,
  `add_info` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `wiki_t`
--

INSERT INTO `wiki_t` (`tittle`, `url`, `add_info`, `goal`) VALUES
('link 2', 'en.wikipedia.org/wiki/Addition', 'this is the wikipedia link for higher information on\naddition ! \n', 'Fundamental 1 digit Addition'),
('link 3', 'kidslearningstation.com', 'Go to the  given website ! ', 'Fundamental 1 digit Addition'),
('link4', 'maths-paly.com', 'after mcq this website is advisable ! :D', 'Fundamental 1 digit Addition');

-- --------------------------------------------------------

--
-- Table structure for table `wik_ans`
--

CREATE TABLE IF NOT EXISTS `wik_ans` (
  `url` varchar(10000) NOT NULL,
  `response` varchar(10000) NOT NULL,
  `goal` varchar(10000) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `wik_ans`
--

INSERT INTO `wik_ans` (`url`, `response`, `goal`, `student_id`) VALUES
('en.wikipedia.org/wiki/Addition', 'WHATEVER ! \nWHAT I THINK ! \n', 'Fundamental 1 digit Addition', 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
