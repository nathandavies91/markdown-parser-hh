<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Interfaces;

interface BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone;

	/**
	 * @var string Parser regex
	 */
	public static string $regex;

	/**
	 * Markup for this type
	 * @param array<string> $content Lines; with their regex values
	 * @return string The markup
	 */
	public static function markup(array $content) : string;
}
