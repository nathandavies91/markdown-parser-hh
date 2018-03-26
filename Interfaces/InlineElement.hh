<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Interfaces;

interface InlineElement
{
	/**
	 * @var array<string> Parser regex
	 */
	public static array<string> $regex;

	/**
	 * Markup for this type
	 * @param array<string> $content Regex values
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string;
}
