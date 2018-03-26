<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class Blockquote extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = true;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = false;

	/**
	 * @var string Parser regex
	 * Example: >{content}  =>  <blockquote>{content}</blockquote>
	 */
	public static string $regex = "/^(>{1,})(?<content>.*)/";

	/**
	 * Markup for the blockquote element
	 * @param array<array<string>> $content Paragraphs within the blockquote, with their regex values: content
	 * @return string The markup
	 */
	public static function markup(array<array<string>> $content) : string
	{
		foreach ($content as $paragraph)
			$markup [] = parent::markup($paragraph["content"], "p");

		return parent::markup($markup, "blockquote");
	}
}
